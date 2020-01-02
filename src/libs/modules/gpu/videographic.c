#include <lcom/lcf.h>

#include "videographic.h"

// int sys_int86(struct reg86 *reg86p);
// Make Linear frame buffer mode available: ModeAttributes.D7 = 1 (Fazer apenas na função modeinfo)

/* Globals */

// KBC
extern uint32_t kernelCallsCount;
extern uint8_t scancode;
extern int kbcHookId;

// TIMER
extern int timerHookId;
extern uint64_t timerIntCounter;


/* Functions */

void *(vg_init)(uint16_t mode)
{

    ///////////// Get info /////////////

    mmap_t mb1_map;

    lm_alloc(BIT(20), &mb1_map);
    vbe_mode_info_t myVbeMode;

    if (vbe_get_mode_info(mode, &myVbeMode) != EXIT_SUCCESS)
        return NULL;

    // Definition of static globals with ModeInofBlock,
    // info returned from vbe_get_mode_info
    H_RES = myVbeMode.XResolution;           /* Horizontal Resolution */
    V_RES = myVbeMode.YResolution;           /* Vertical Resolution */
    BITS_PER_PIXEL = myVbeMode.BitsPerPixel; /* Color Depth */

    // phys_bytes VRAM_PHYS_ADDR = myVbeMode.PhysBasePtr;    /* Physical Adress of VRAM - returns address */

    // New Variables for Mapping VRAM to the process' address space
    unsigned int VRAM_SIZE = H_RES * V_RES * ceil(BITS_PER_PIXEL / 8.0); /* Length of Region to be mapped */
    struct minix_mem_range MEMORY_RANGE;                                 /* Physical Memory Range - Struct defined by LCOM */
    void *VIDEO_MEMORY_FRAME_BUFF_ADDR;                                  /* Frame-Buffer VideoMemory address */
    int R;                                                               /* Variable to store number of error, if the case */

    ///////////// Allow memory mapping /////////////

    // Define memory range state
    MEMORY_RANGE.mr_base = (phys_bytes)myVbeMode.PhysBasePtr; /* Lowest memory address in range */
    MEMORY_RANGE.mr_limit = MEMORY_RANGE.mr_base + VRAM_SIZE; /* Highest memory address in range */

    ///////////// Granting permission to map a given address range /////////////

    // Because the process has access to the mapped physical memory,
    // Minix requires the process to have not only the necessary permissions
    // to execute that call, but it must also have the permission to map the
    // desired physical address range. We use MINIX 3 kernel call

    // int sys_privctl(endpoint_t proc_ep, int request, void *p)
    // 1st parameter: process whose privileges will be affected
    // 2nd parameter: type of request (6 = Add memory range (struct mem_range))
    if (OK != (R = sys_privctl(SELF, SYS_PRIV_ADD_MEM, &MEMORY_RANGE)))
        panic("sys_privctl (ADD_MEM) failed: %d\n", R);

    ///////////// Mapping memory /////////////

    // *vm_map_phys(endpoint_t who, void *phaddr, size_t len)
    // 1º parameter: is a value that identifies the process on whose address
    //               space the physical memory region should be mapped.
    //
    // 2º parameter: phaddr specifies the physical address of the first memory byte
    //               in that region and len the region's length (base: lowest memory address in the range)
    //
    // 3º parameter: length of the physical memory region that should be mapped
    //
    // Returns: a pointer to the virtual address (of the first physical memory position) on
    // which the physical address range was mapped.

    VIDEO_MEMORY_FRAME_BUFF_ADDR = vm_map_phys(SELF, (void *)MEMORY_RANGE.mr_base, VRAM_SIZE);
    ptrToGpuVAddr = VIDEO_MEMORY_FRAME_BUFF_ADDR;

    if (VIDEO_MEMORY_FRAME_BUFF_ADDR == MAP_FAILED)
        panic("couldn't map video memory");

    doubleBuffer = malloc(VRAM_SIZE);

    ///////////// MODIFY GRAPHIC MODE /////////////

    // int sys_int86(struct reg86 * reg86p)
    //
    // Returns: OK, in the case of success / DEFAULT in the case of failure
    // Parameter: value of type struct reg86 *reg86p (allows to specify the values of the interrupt number and of the processor registers)

    // Initialize struct and function to empty the register REG_86 struct
    struct reg86 REG_86;
    memset(&REG_86, 0, sizeof(REG_86));

    REG_86.ah = VBE_FUNC_RETURN_SUCCESS_AX;

    // Identify VBE Function (SetVideoMode)
    REG_86.ax = VBE_FUNC_SET_MODE_AX;

    REG_86.bx = mode | SET_LINEAR_FRAME_BUFFER;

    // Indentify BIOS Call - Video Services
    REG_86.intno = VBE_INT_INTERFACE;

    // Lost video mode if FAILED
    if (sys_int86(&REG_86) == EXIT_FAILURE)
    {
        printf("Setting VBE Mode(set_vbe_mode) failed in sys_int86 \n");
        return NULL;
    }

    lm_free(&mb1_map);
    return VIDEO_MEMORY_FRAME_BUFF_ADDR;
}

void(vg_exit_gfx_on_key_press)(uint8_t key_breakcode)
{

    uint8_t bitNum = KBC_IRQ;
    int irqSet = BIT(bitNum);

    _Bool irqSetIsValid = kbc_subscribe_int(&bitNum) == EXIT_SUCCESS;

    if (irqSetIsValid)
    {

        int request;
        int ipcStatus;
        message msg;

        uint8_t scancodeArr[2];
        scancodeArr[0] = 0;

        _Bool scancodeHasTwoBytes = false;

        while (scancodeArr[0] != key_breakcode)
        {

            request = driver_receive(ANY, &msg, &ipcStatus);
            if (request == EXIT_SUCCESS)
            {
                if (is_ipc_notify(ipcStatus))
                {
                    if (_ENDPOINT_P(msg.m_source) == HARDWARE)
                    {
                        if (msg.m_notify.interrupts & irqSet)
                        {

                            kbc_ih();

                            if (kbc_two_byte_scancode(scancode))
                            {
                                scancodeArr[1] = scancode;
                                scancodeHasTwoBytes = true;
                                continue;
                            }
                            else
                                scancodeArr[0] = scancode;

                            if (scancodeHasTwoBytes)
                                scancodeHasTwoBytes = false;
                        }
                    }
                }
            }
            else
            {
                printf("driver_receive failed with: %d", request);
                continue;
            }
        }

        kbc_unsubscribe_int();
        vg_exit();
    }
    else
        vg_exit();
}

int(vg_draw_point)(uint16_t x, uint16_t y, uint32_t color){

    uint8_t *ptrToVAddr = ptrToGpuVAddr;

    if (x > H_RES || y > V_RES)
        return EXIT_FAILURE;

    unsigned int pxBytes = ceil(BITS_PER_PIXEL / 8.0);

    ptrToVAddr = (uint8_t*) doubleBuffer + (((H_RES * y) + x) * pxBytes);

    if (color != xpm_transparency_color(XPM_8_8_8)){
        for (unsigned int i = 0; i < pxBytes; i++){
            *ptrToVAddr = color >> (8 * i);
            ptrToVAddr++;
        }
    }

    return EXIT_SUCCESS;
}

int(vg_draw_hline)(uint16_t x, uint16_t y, uint16_t len, uint32_t color){

    for (int i = 0; i < len; i++){
        if (vg_draw_point(x + i, y, color) != EXIT_SUCCESS)
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int(vg_draw_rectangle)(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color){

    for (int i = 0; i < height; i++){
        if (vg_draw_hline(x, y + i, width, color) != EXIT_SUCCESS)
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void(vg_reset_frame)(){
    // memset(ptrToGpuVAddr, 0, H_RES * V_RES * ceil(BITS_PER_PIXEL / 8.0));
    memset(doubleBuffer, 0, H_RES * V_RES * ceil(BITS_PER_PIXEL / 8.0));
}

void (vg_double_buffering)(){
    memcpy(ptrToGpuVAddr, doubleBuffer, H_RES * V_RES * ceil(BITS_PER_PIXEL / 8.0));
}

sprite_t vg_load_sprite(xpm_map_t xpm){

    sprite_t newSprite;

    xpm_image_t img;
    uint8_t* pixmap;

    pixmap = xpm_load(xpm, XPM_8_8_8, &img);

    newSprite.width = img.width;
    newSprite.height = img.height;
    newSprite.start_x = 0;
    newSprite.start_y = 0;
    newSprite.pixmap = pixmap;

    return newSprite;
}

int vg_render_xpm(xpm_map_t xpm, uint16_t x, uint16_t y)
{

    // uint8_t*() xpm_load(xpm_map_t map, enum xpm_image_type type, xpm_image_t *img)
    // type can be XPM_1_5_5_5, XPM_5_6_5, XPM_8_8_8 or XPM_8_8_8_8

    xpm_image_t img;
    uint8_t* pixmap;
    pixmap = xpm_load(xpm, XPM_8_8_8, &img);

    for (int i = 0; i < img.height; i++)
    {
        for (int j = 0; j < img.width; j++)
        {

            //uint32_t *color = (uint32_t *)(pixmap + (i*img.width + j)*(BITS_PER_PIXEL/8));
            uint32_t color = 0;
            for (int k = 0; k < BITS_PER_PIXEL / 8.0; k++)
                color |= (*(pixmap + (i * img.width + j) * (BITS_PER_PIXEL / 8) + k)) << (k * 8);

            if (vg_draw_point(x + j, y + i, color) != EXIT_SUCCESS)
            {
                vg_exit();
                return EXIT_FAILURE;
            }
        }
    }

    free(pixmap);

    return EXIT_SUCCESS;
}

int vg_render_sprite(sprite_t sp, uint16_t x, uint16_t y)
{

    // uint8_t*() xpm_load(xpm_map_t map, enum xpm_image_type type, xpm_image_t *img)
    // type can be XPM_1_5_5_5, XPM_5_6_5, XPM_8_8_8 or XPM_8_8_8_8

    for (int i = 0; i < sp.height; i++)
    {
        for (int j = 0; j < sp.width; j++)
        {

            //uint32_t *color = (uint32_t *)(pixmap + (i*img.width + j)*(BITS_PER_PIXEL/8));
            uint32_t color = 0;
            for (int k = 0; k < BITS_PER_PIXEL / 8.0; k++)
                color |= (*(sp.pixmap + (i * sp.width + j) * (BITS_PER_PIXEL / 8) + k)) << (k * 8);

            if (vg_draw_point(x + j, y + i, color) != EXIT_SUCCESS)
            {
                vg_exit();
                return EXIT_FAILURE;
            }
        }
    }

    return EXIT_SUCCESS;
}

int(vg_rm_xpm)(xpm_map_t xpm, uint16_t x, uint16_t y)
{

    // uint8_t*() xpm_load(xpm_map_t map, enum xpm_image_type type, xpm_image_t *img)
    // type can be XPM_1_5_5_5, XPM_5_6_5, XPM_8_8_8 or XPM_8_8_8_8

    xpm_image_t img;
    uint8_t *pixmap;
    pixmap = xpm_load(xpm, XPM_8_8_8, &img);

    for (int i = 0; i < img.height; i++)
    {
        for (int j = 0; j < img.width; j++)
        {
            if (vg_draw_point(x + j, y + i, 0x000000) != EXIT_SUCCESS)
            {
                vg_exit();
                return EXIT_FAILURE;
            }
        }
    }

    free(pixmap);

    return EXIT_SUCCESS;
}

int(vg_rm_sprite)(sprite_t sp, uint16_t x, uint16_t y)
{

    // uint8_t*() xpm_load(xpm_map_t map, enum xpm_image_type type, xpm_image_t *img)
    // type can be XPM_1_5_5_5, XPM_5_6_5, XPM_8_8_8 or XPM_8_8_8_8

    for (int i = 0; i < sp.height; i++)
    {
        for (int j = 0; j < sp.width; j++)
        {
            if (vg_draw_point(x + j, y + i, 0x000000) != EXIT_SUCCESS)
            {
                vg_exit();
                return EXIT_FAILURE;
            }
        }
    }

    return EXIT_SUCCESS;
}

int(vg_keyframe_transition_xpm)(xpm_map_t xpm, uint16_t xi, uint16_t yi, uint16_t xf, uint16_t yf, int16_t speed, uint8_t fr_rate)
{

    uint32_t totalFrames = sys_hz() / fr_rate;
    uint16_t frameCounter = 0;

    uint16_t x = xi;
    uint16_t y = yi;

    // timer subscription
    uint8_t timerBitNum = TIMER0_IRQ;
    int timerIrqSet = BIT(timerBitNum);

    _Bool timerIrqSetIsValid = timer_subscribe_int(&timerBitNum) == EXIT_SUCCESS;

    // keyboard subscription
    uint8_t kbcBitNum = KBC_IRQ;
    int kbcIrqSet = BIT(kbcBitNum);

    _Bool kbcIrqSetIsValid = kbc_subscribe_int(&kbcBitNum) == EXIT_SUCCESS;

    if (timerIrqSetIsValid && kbcIrqSetIsValid)
    {

        vg_render_xpm(xpm, x, y);

        int request;
        int ipcStatus;
        message msg;

        uint8_t scancodeArr[2];
        scancodeArr[0] = 0;

        _Bool scancodeHasTwoBytes = false;

        // Interrupt loop
        while (scancodeArr[0] != 0x81 && (x != xf || y != yf))
        {

            request = driver_receive(ANY, &msg, &ipcStatus);
            if (request == EXIT_SUCCESS)
            {
                if (is_ipc_notify(ipcStatus))
                {
                    if (_ENDPOINT_P(msg.m_source) == HARDWARE)
                    {

                        // KBC interrupt handling

                        if (msg.m_notify.interrupts & kbcIrqSet)
                        {

                            kbc_ih();

                            if (kbc_two_byte_scancode(scancode))
                            {
                                scancodeArr[1] = scancode;
                                scancodeHasTwoBytes = true;
                                continue;
                            }
                            else
                                scancodeArr[0] = scancode;

                            if (scancodeHasTwoBytes)
                                scancodeHasTwoBytes = false;
                        }

                        // Timer interrupt handling

                        if (msg.m_notify.interrupts & timerIrqSet)
                        {
                            timer_ih();
                            frameCounter++;

                            if (frameCounter == totalFrames)
                            {
                                timerIntCounter = 0;
                                frameCounter = 0;

                                if (speed < 0)
                                {

                                    if (x < xf)
                                    {
                                        vg_rm_xpm(xpm, x, y);

                                        if (frameCounter == -speed)
                                            x++;

                                        vg_render_xpm(xpm, x, y);
                                    }

                                    if (y < yf)
                                    {
                                        vg_rm_xpm(xpm, x, y);

                                        if (frameCounter == -speed)
                                            y++;
                                        vg_render_xpm(xpm, x, y);
                                    }
                                }
                                else
                                {
                                    if ((xf < xi))
                                    {
                                        if ((x - speed) > xf)
                                        {
                                            vg_rm_xpm(xpm, x, y);

                                            x -= speed;
                                            vg_render_xpm(xpm, x, y);
                                        }
                                        else if ((x - speed) <= xf)
                                        {
                                            vg_rm_xpm(xpm, x, y);

                                            x = xf;
                                            vg_render_xpm(xpm, x, y);
                                        }
                                    }
                                    else
                                    {
                                        if ((x + speed) < xf)
                                        {
                                            vg_rm_xpm(xpm, x, y);

                                            x += speed;
                                            vg_render_xpm(xpm, x, y);
                                        }
                                        else if ((x + speed) >= xf)
                                        {
                                            vg_rm_xpm(xpm, x, y);

                                            x = xf;
                                            vg_render_xpm(xpm, x, y);
                                        }
                                    }

                                    if (yf < yi)
                                    {
                                        if ((y - speed) < yf)
                                        {
                                            vg_rm_xpm(xpm, x, y);

                                            y -= speed;
                                            vg_render_xpm(xpm, x, y);
                                        }
                                        else if ((y - speed) <= yf)
                                        {
                                            vg_rm_xpm(xpm, x, y);

                                            y = yf;
                                            vg_render_xpm(xpm, x, y);
                                        }
                                    }
                                    else
                                    {
                                        if ((y + speed) > yf)
                                        {
                                            vg_rm_xpm(xpm, x, y);

                                            y += speed;
                                            vg_render_xpm(xpm, x, y);
                                        }
                                        else if ((y + speed) >= yf)
                                        {
                                            vg_rm_xpm(xpm, x, y);

                                            y = yf;
                                            vg_render_xpm(xpm, x, y);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                printf("driver_receive failed with: %d", request);
                continue;
            }
        }

        kbc_unsubscribe_int();
        timer_unsubscribe_int();
        timer_set_frequency(0, sys_hz());

        vg_exit();
    }
    else
    {
        vg_exit();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int(vg_keyframe_transition)(sprite_t sp, uint16_t xi, uint16_t yi, uint16_t xf, uint16_t yf, int16_t speed, uint8_t fr_rate)
{

    uint32_t totalFrames = sys_hz() / fr_rate;
    uint16_t frameCounter = 0;

    uint16_t x = xi;
    uint16_t y = yi;

    // timer subscription
    uint8_t timerBitNum = TIMER0_IRQ;
    int timerIrqSet = BIT(timerBitNum);

    _Bool timerIrqSetIsValid = timer_subscribe_int(&timerBitNum) == EXIT_SUCCESS;

    // keyboard subscription
    uint8_t kbcBitNum = KBC_IRQ;
    int kbcIrqSet = BIT(kbcBitNum);

    _Bool kbcIrqSetIsValid = kbc_subscribe_int(&kbcBitNum) == EXIT_SUCCESS;

    if (timerIrqSetIsValid && kbcIrqSetIsValid)
    {

        vg_render_sprite(sp, x, y);

        int request;
        int ipcStatus;
        message msg;

        uint8_t scancodeArr[2];
        scancodeArr[0] = 0;

        _Bool scancodeHasTwoBytes = false;

        // Interrupt loop
        while (scancodeArr[0] != 0x81 && (x != xf || y != yf))
        {

            request = driver_receive(ANY, &msg, &ipcStatus);
            if (request == EXIT_SUCCESS)
            {
                if (is_ipc_notify(ipcStatus))
                {
                    if (_ENDPOINT_P(msg.m_source) == HARDWARE)
                    {

                        // KBC interrupt handling

                        if (msg.m_notify.interrupts & kbcIrqSet)
                        {

                            kbc_ih();

                            if (kbc_two_byte_scancode(scancode))
                            {
                                scancodeArr[1] = scancode;
                                scancodeHasTwoBytes = true;
                                continue;
                            }
                            else
                                scancodeArr[0] = scancode;

                            if (scancodeHasTwoBytes)
                                scancodeHasTwoBytes = false;
                        }

                        // Timer interrupt handling

                        if (msg.m_notify.interrupts & timerIrqSet)
                        {
                            timer_ih();
                            frameCounter++;

                            if (frameCounter == totalFrames)
                            {
                                timerIntCounter = 0;
                                frameCounter = 0;

                                if (speed < 0)
                                {

                                    if (x < xf)
                                    {
                                        vg_rm_sprite(sp, x, y);

                                        if (frameCounter == -speed)
                                            x++;

                                        vg_render_sprite(sp, x, y);
                                    }

                                    if (y < yf)
                                    {
                                        vg_rm_sprite(sp, x, y);

                                        if (frameCounter == -speed)
                                            y++;
                                        vg_render_sprite(sp, x, y);
                                    }
                                }
                                else
                                {
                                    if ((xf < xi))
                                    {
                                        if ((x - speed) > xf)
                                        {
                                            vg_rm_sprite(sp, x, y);

                                            x -= speed;
                                            vg_render_sprite(sp, x, y);
                                        }
                                        else if ((x - speed) <= xf)
                                        {
                                            vg_rm_sprite(sp, x, y);

                                            x = xf;
                                            vg_render_sprite(sp, x, y);
                                        }
                                    }
                                    else
                                    {
                                        if ((x + speed) < xf)
                                        {
                                            vg_rm_sprite(sp, x, y);

                                            x += speed;
                                            vg_render_sprite(sp, x, y);
                                        }
                                        else if ((x + speed) >= xf)
                                        {
                                            vg_rm_sprite(sp, x, y);

                                            x = xf;
                                            vg_render_sprite(sp, x, y);
                                        }
                                    }

                                    if (yf < yi)
                                    {
                                        if ((y - speed) < yf)
                                        {
                                            vg_rm_sprite(sp, x, y);

                                            y -= speed;
                                            vg_render_sprite(sp, x, y);
                                        }
                                        else if ((y - speed) <= yf)
                                        {
                                            vg_rm_sprite(sp, x, y);

                                            y = yf;
                                            vg_render_sprite(sp, x, y);
                                        }
                                    }
                                    else
                                    {
                                        if ((y + speed) > yf)
                                        {
                                            vg_rm_sprite(sp, x, y);

                                            y += speed;
                                            vg_render_sprite(sp, x, y);
                                        }
                                        else if ((y + speed) >= yf)
                                        {
                                            vg_rm_sprite(sp, x, y);

                                            y = yf;
                                            vg_render_sprite(sp, x, y);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                printf("driver_receive failed with: %d", request);
                continue;
            }
        }

        kbc_unsubscribe_int();
        timer_unsubscribe_int();
        timer_set_frequency(0, sys_hz());

        vg_exit();
    }
    else
    {
        vg_exit();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
