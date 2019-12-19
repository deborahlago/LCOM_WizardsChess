#include "game_funcs.h"

int game_load_assets(struct GAME_ASSETS *game_assets){

    if (vg_load_sprites(game_assets, xpm_btns, ARRAY_SIZE(xpm_btns), BTNS) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    if (vg_load_sprites(game_assets, xpm_bgs, ARRAY_SIZE(xpm_bgs), BGS) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    if (vg_load_sprites(game_assets, xpm_pieces, ARRAY_SIZE(xpm_pieces), PIECES) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    if (vg_load_sprites(game_assets, xpm_borders, ARRAY_SIZE(xpm_borders), BORDERS) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    if (vg_load_sprites(game_assets, xpm_characters, ARRAY_SIZE(xpm_characters), CHARS) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    if (vg_load_sprites(game_assets, xpm_logos, ARRAY_SIZE(xpm_logos), LOGOS) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    if (vg_load_sprites(game_assets, xpm_numbers, ARRAY_SIZE(xpm_numbers), NUMBERS) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    if (vg_load_sprites(game_assets, xpm_visual_fx, ARRAY_SIZE(xpm_visual_fx), V_FX) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

/* GAME LOOP */

int game_run(struct GAME_ASSETS* game_assets, struct GAME_STATE* game_state){

    uint8_t stByte;

    uint32_t totalFrames = sys_hz() / 2;    // 30fps
    uint16_t frameCounter = 0;

    uint16_t x = game_state->mouse_x_pos;
    uint16_t y = game_state->mouse_y_pos;

    // timer subscription
    uint8_t timerBitNum = TIMER0_IRQ;
    int timerIrqSet = BIT(timerBitNum);

    _Bool timerIrqSetIsValid = timer_subscribe_int(&timerBitNum) == EXIT_SUCCESS;

    // keyboard subscription
    uint8_t kbcBitNum = KBC_IRQ;
    int kbcIrqSet = BIT(kbcBitNum);

    _Bool kbcIrqSetIsValid = kbc_subscribe_int(&kbcBitNum) == EXIT_SUCCESS;

    // mouse subscription
    uint32_t packetsGenerated = 0;
    uint8_t mouseBitNum = PS2_IRQ;
    int mouseIrqSet = BIT(mouseBitNum);

    _Bool mouseIrqSetIsValid =  mouse_subscribe_int(&mouseBitNum) == EXIT_SUCCESS;


    if (mouse_enable_data_report(&stByte) != PS2_WRITE_CMD_ERR) {

        if (timerIrqSetIsValid && kbcIrqSetIsValid && mouseIrqSetIsValid) {

            switch (game_state->curr_window){
                case 0: {
                    game_state->gui_fn = gui_start_window(game_assets);
                    break;
                }
                case 1: {
                    game_state->gui_fn = gui_main_menu(game_assets);
                    break;
                }
                case 2: {
                    game_state->gui_fn = gui_char_sel_window(game_assets);
                    break;
                }
                case 3: {
                    break;
                }
                case 4: {
                    game_state->gui_fn = gui_game_window(game_assets, game_state->p1_house, game_state->p2_house, game_state->pieces_x_pos, game_state->pieces_y_pos);
                    break;
                }
                case 5: {
                    game_state->gui_fn = gui_in_game_menu(game_assets);
                    break;
                }
                default: {
                    game_state->gui_fn = gui_start_window(game_assets);
                    break;
                }
            }

            game_state->gui_fn();

            int request;
            int ipcStatus;
            message msg;

            uint8_t scancodeArr[2];
            scancodeArr[0] = 0;

            _Bool scancodeHasTwoBytes = false;

            // Interrupt loop
            while (true) {

                request = driver_receive(ANY, &msg, &ipcStatus);
                if (request == EXIT_SUCCESS) {
                    if (is_ipc_notify(ipcStatus)) {
                        if (_ENDPOINT_P(msg.m_source) == HARDWARE) {

                            // KBC interrupt handling

                            if (msg.m_notify.interrupts & kbcIrqSet) {

                                kbc_ih();

                                if (kbc_two_byte_scancode(scancode)) {
                                    scancodeArr[1] = scancode;
                                    scancodeHasTwoBytes = true;
                                    continue;
                                } else scancodeArr[0] = scancode;

                                if (scancodeHasTwoBytes) scancodeHasTwoBytes = false;

                                // TODO implement keyboard input logic
                            }


                            // Timer interrupt handling

                            if (msg.m_notify.interrupts & timerIrqSet) {
                                timer_ih();
                                frameCounter++;

                                if (frameCounter == totalFrames) {

                                    timerIntCounter = 0;
                                    frameCounter = 0;

                                    // TODO game logic
                                }
                            }
                        }
                    }
                } else {
                    printf("driver_receive failed with: %d", request);
                    continue;
                }

                if (game_state->leave) break;
            }

            kbc_unsubscribe_int();
            timer_unsubscribe_int();
            timer_set_frequency(0, sys_hz());

            vg_exit();
        }
        else {
            vg_exit();
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;

}
