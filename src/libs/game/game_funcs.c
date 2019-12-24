#include "game_funcs.h"


/* Globals */

// KBC
extern int kbcHookId;
extern uint32_t kernelCallsCount;
extern uint8_t scancode;

// TIMER 0
extern int timerHookId;
extern uint64_t timerIntCounter;

// PS/2
extern int ps2HookId;
extern uint8_t pktByte;
extern int pktCounter;
extern struct packet pkt;
extern _Bool gestureComplete;

// XPM ARRAYS
xpm_map_t xpm_bgs[5] = {start_BG, mainMenu_BG, selectPlayer_BG, board_BG, inGameMenu_BG};
xpm_map_t xpm_borders[2] = {left_player_board_button, right_player_board_button};
xpm_map_t xpm_btns[9] = {title, start_button, singleplayer_button, multiplayer_button, exit_button, changeGameMode_button, endGame_button, inGameMenu_button, reStartGame_button};
xpm_map_t xpm_characters[8] = {godric_gif_img, godric_button, helga_gif_img, helga_button, rowena_gif_img, rowena_button, salazar_gif_img, salazar_button};
xpm_map_t xpm_logos[4] = {gryffindor_logo, hufflepuff_logo, ravenclaw_logo, slytherin_logo};
xpm_map_t xpm_pieces[12] = {whitePawn, whiteBishop, whiteHorse, whiteTower, whiteQueen, whiteKing, blackPawn, blackBishop, blackHorse, blackTower, blackQueen, blackKing};
xpm_map_t xpm_visual_fx[2] = {selectedMenu_visualFx, selectInGameMenu_visualFx};
xpm_map_t xpm_numbers[11] = {zero_xpm, one_xpm, two_xpm, three_xpm, four_xpm, five_xpm, six_xpm, seven_xpm, eight_xpm, nine_xpm, colon_xpm};


/* Functions */

int game_load_assets(struct GAME_ASSETS* game_assets){

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

    uint32_t totalFrames = sys_hz() / 30;    // 30fps
    uint16_t frameCounter = 0;

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


    if (mouse_enable_data_report(&stByte) != PS2_WRITE_CMD_ERR){

        if (timerIrqSetIsValid && kbcIrqSetIsValid && mouseIrqSetIsValid){

            switch (game_state->curr_window){
                case 0: {
                    game_state->switch_window = &gui_start_window;
                    break;
                }
                case 1: {
                    game_state->switch_window = &gui_main_menu;
                    break;
                }
                case 2: {
                    game_state->switch_window = &gui_char_sel_window;
                    break;
                }
                case 3: {
                    break;
                }
                case 4: {
                    game_state->switch_window = &gui_game_window;
                    break;
                }
                case 5: {
                    game_state->switch_window = &gui_in_game_menu;
                    break;
                }
                default: {
                    game_state->switch_window = &gui_start_window;
                    break;
                }
            }

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

                                    // RENDER
                                    game_state->switch_window(game_assets, game_state);
                                }
                            }


                            // Mouse interrupt handling

                            if (msg.m_notify.interrupts & mouseIrqSet){

                                // Handles a new interrupt
                                // Parses all the packet bytes into the
                                // bytes array in the packet struct
                                mouse_ih();
                                mouse_parse_packet_byte();

                                if (pktCounter == 3){
                                    mouse_assemble_packet(&pkt);
                                    mouse_print_packet(&pkt);

                                    pktCounter = 0;
                                    timerIntCounter = 0;
                                    packetsGenerated++;
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
            printf("INVALID_IRQ");
            vg_exit();
            return EXIT_FAILURE;
        }
    }
    else printf("COULD NOT ENABLE MOUSE DATA REPORTING!");

    return EXIT_SUCCESS;

}
