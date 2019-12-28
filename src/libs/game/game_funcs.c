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


/* Functions */

int game_load_assets(game_assets_t* game_assets){

    /* Mouse */

    game_assets->mouse_cursor = vg_load_sprite(cursor_normal);

    /* Backgrounds */

    game_assets->start_bg = vg_load_sprite(start_BG);
    game_assets->main_menu_bg = vg_load_sprite(mainMenu_BG);
    game_assets->player_sel_bg = vg_load_sprite(selectPlayer_BG);
    game_assets->board_bg = vg_load_sprite(board_BG);
    game_assets->in_game_menu_bg = vg_load_sprite(inGameMenu_BG);


    /* Buttons */

    game_assets->title = vg_load_sprite(title);
    game_assets->start_btn = vg_load_sprite(start_button);
    game_assets->singleplayer_btn = vg_load_sprite(singleplayer_button);
    game_assets->multiplayer_btn = vg_load_sprite(multiplayer_button);
    game_assets->exit_btn = vg_load_sprite(exit_button);
    game_assets->change_game_mode_btn = vg_load_sprite(changeGameMode_button);
    game_assets->end_game_btn = vg_load_sprite(endGame_button);
    game_assets->in_game_menu_btn = vg_load_sprite(inGameMenu_button);
    game_assets->restart_game_btn = vg_load_sprite(reStartGame_button);


    /* Borders */

    game_assets->left_p_border = vg_load_sprite(left_player_board_button);
    game_assets->right_p_border = vg_load_sprite(right_player_board_button);


    /* Logos */

    game_assets->gryff_logo = vg_load_sprite(gryffindor_logo);
    game_assets->huffle_logo = vg_load_sprite(hufflepuff_logo);
    game_assets->raven_logo = vg_load_sprite(ravenclaw_logo);
    game_assets->slyth_logo = vg_load_sprite(slytherin_logo);


    /* Characters */

    game_assets->godric_img = vg_load_sprite(godric_gif_img);
    game_assets->godric_title = vg_load_sprite(godric_button);

    game_assets->helga_img = vg_load_sprite(helga_gif_img);
    game_assets->helga_title = vg_load_sprite(helga_button);

    game_assets->rowena_img = vg_load_sprite(rowena_gif_img);
    game_assets->rowena_title = vg_load_sprite(rowena_button);

    game_assets->salazar_img = vg_load_sprite(salazar_gif_img);
    game_assets->salazar_title = vg_load_sprite(salazar_button);


    /* Pieces */

    game_assets->w_pawn = vg_load_sprite(whitePawn);
    game_assets->w_bishop = vg_load_sprite(whiteBishop);
    game_assets->w_knight = vg_load_sprite(whiteHorse);
    game_assets->w_rook = vg_load_sprite(whiteTower);
    game_assets->w_queen = vg_load_sprite(whiteQueen);
    game_assets->w_knight = vg_load_sprite(whiteKing);

    game_assets->b_pawn = vg_load_sprite(blackPawn);
    game_assets->b_bishop = vg_load_sprite(blackBishop);
    game_assets->b_knight = vg_load_sprite(blackHorse);
    game_assets->b_rook = vg_load_sprite(blackTower);
    game_assets->b_queen = vg_load_sprite(blackQueen);
    game_assets->b_king = vg_load_sprite(blackKing);


    /* Numbers */

    game_assets->zero_num = vg_load_sprite(zero_xpm);
    game_assets->one_num = vg_load_sprite(one_xpm);
    game_assets->two_num = vg_load_sprite(two_xpm);
    game_assets->three_num = vg_load_sprite(three_xpm);
    game_assets->four_num = vg_load_sprite(four_xpm);
    game_assets->five_num = vg_load_sprite(five_xpm);
    game_assets->six_num = vg_load_sprite(six_xpm);
    game_assets->seven_num = vg_load_sprite(seven_xpm);
    game_assets->eight_num = vg_load_sprite(eight_xpm);
    game_assets->nine_num = vg_load_sprite(nine_xpm);
    game_assets->colon_num = vg_load_sprite(colon_xpm);


    /* Visual FXs */

    game_assets->transparent = vg_load_sprite(transp);
    game_assets->hover_main_menu = vg_load_sprite(selectedMenu_visualFx);
    game_assets->hover_in_game_menu = vg_load_sprite(selectInGameMenu_visualFx);

    return EXIT_SUCCESS;
}

void game_update_cursor(game_state_t* game_state){

    game_state->mouse_prev_x_pos = game_state->mouse_curr_x_pos;
    game_state->mouse_prev_y_pos = game_state->mouse_curr_y_pos;

    // Update X pos
    if (game_state->mouse_curr_x_pos + (game_state->curr_mouse_event.delta_x*0.4) > 1280)
        game_state->mouse_curr_x_pos = 1270;
    else if (game_state->mouse_curr_x_pos + (game_state->curr_mouse_event.delta_x*0.4) < 0)
        game_state->mouse_curr_x_pos = 10;
    else
        game_state->mouse_curr_x_pos += game_state->curr_mouse_event.delta_x * 0.4;


    // Update Y pos
    if (game_state->mouse_curr_y_pos - (game_state->curr_mouse_event.delta_y*0.4) > 1014)
        game_state->mouse_curr_y_pos = 1014;
    else if (game_state->mouse_curr_y_pos - game_state->curr_mouse_event.delta_y < 0)
        game_state->mouse_curr_y_pos = 10;
    else
        game_state->mouse_curr_y_pos -= game_state->curr_mouse_event.delta_y * 0.4;
}

struct mouse_event game_mouse_ev_handler(struct packet* pkt, game_state_t* game_state){

    struct mouse_event curr_event;

    // Left button released
    if (game_state->lb && !pkt->lb) curr_event.type = LB_REL;

        // Left button pressed
    else if (!game_state->lb && pkt->lb) curr_event.type = LB_PRE;

        // Right button released
    else if (game_state->rb && !pkt->rb) curr_event.type = RB_REL;

        // Right button pressed
    else if (!game_state->rb && pkt->rb) curr_event.type = RB_PRE;

        // Mouse movement
    else if (pkt->delta_x != 0 || pkt->delta_x != 0){
        curr_event.type = MOV;
        curr_event.delta_x = pkt->delta_x;
        curr_event.delta_y = pkt->delta_y;
    }

        // Middle button pressed
    else if (game_state->mb && !pkt->mb) curr_event.type = OTHER;

        // Middle button released
    else if (!game_state->mb && pkt->mb) curr_event.type = OTHER;

        // Other scenarios
    else curr_event.type = OTHER;


    // Update mouse button values
    game_state->lb = pkt->lb;
    game_state->rb = pkt->rb;
    game_state->mb = pkt->mb;

    return curr_event;
}

void game_update_state(game_assets_t* game_assets, game_state_t* game_state){

    switch (game_state->curr_state){
        case START_WINDOW: {

            switch (game_state->curr_event){
                case TIMER: {
                    gui_start_window(game_assets, game_state);
                    break;
                }
                case MOUSE: {
                    game_update_cursor(game_state);

                }
                case KEYBOARD: {
                    break;
                }
                case RTC: {
                    break;
                }
                default : {

                }
            }

            break;
        }
        case MAIN_MENU: {

            switch (game_state->curr_event){
                case TIMER: {
                    gui_main_menu(game_assets, game_state);
                    break;
                }
                case MOUSE: {
                    break;
                }
                case KEYBOARD: {
                    break;
                }
                case RTC: {
                    break;
                }
                default: {
                    break;
                }
            }

            break;
        }
        case CHAR_SELECT: {

            switch (game_state->curr_event) {
                case TIMER: {
                    gui_char_sel_window(game_assets, game_state);
                    break;
                }
                case MOUSE: {
                    break;
                }
                case KEYBOARD: {
                    break;
                }
                case RTC: {
                    break;
                }
                default: {
                    break;
                }
            }

            break;
        }
        case GAME_MODE_SELECT: {
            break;
        }
        case PLAY_GAME: {

            switch (game_state->curr_event) {
                case TIMER: {
                    gui_game_window(game_assets, game_state);
                    break;
                }
                case MOUSE: {
                    break;
                }
                case KEYBOARD: {
                    break;
                }
                case RTC: {
                    break;
                }
                default: {
                    break;
                }
            }

            break;
        }
        case IN_GAME_MENU: {

            switch (game_state->curr_event) {
                case TIMER: {
                    gui_in_game_menu(game_assets, game_state);
                    break;
                }
                case MOUSE: {
                    break;
                }
                case KEYBOARD: {
                    break;
                }
                case RTC: {
                    break;
                }
                default: {
                    break;
                }
            }

            break;
        }
        default: {

            switch (game_state->curr_event) {
                case TIMER: {
                    gui_start_window(game_assets, game_state);
                    break;
                }
                case MOUSE: {
                    break;
                }
                case KEYBOARD: {
                    break;
                }
                case RTC: {
                    break;
                }
                default: {
                    break;
                }
            }

            break;
        }
    }
}

int game_run(game_assets_t* game_assets, game_state_t* game_state){

    vg_init(VBE_MODE_11BH);

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

            int request;
            int ipcStatus;
            message msg;

            uint8_t scancodeArr[2];
            scancodeArr[0] = 0;

            _Bool scancodeHasTwoBytes = false;

            // Interrupt loop
            while (scancodeArr[0] != KBC_ESC_KEY_BREAKCODE) {

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
                                }
                                else scancodeArr[0] = scancode;

                                if (scancodeHasTwoBytes){
                                    kbd_print_scancode(kbc_is_make_code(scancodeArr[1]), 2, scancodeArr);
                                    scancodeHasTwoBytes = false;
                                }
                                else kbd_print_scancode(kbc_is_make_code(scancodeArr[0]), 1, scancodeArr);

                                // UPDATE
                                game_state->curr_event = KEYBOARD;
                                game_update_state(game_assets, game_state);

                            }


                            // Timer interrupt handling

                            if (msg.m_notify.interrupts & timerIrqSet) {
                                timer_ih();
                                frameCounter++;

                                if (frameCounter == totalFrames) {

                                    timerIntCounter = 0;
                                    frameCounter = 0;

                                    // UPDATE
                                    game_state->curr_event = TIMER;
                                    game_update_state(game_assets, game_state);
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
                                    mouse_assemble_packet();
                                    game_state->curr_mouse_event = game_mouse_ev_handler(&pkt, game_state);

                                    pktCounter = 0;
                                    timerIntCounter = 0;
                                    packetsGenerated++;
                                }

                                // UPDATE
                                game_state->curr_event = MOUSE;
                                game_update_state(game_assets, game_state);
                            }
                        }
                    }
                }
                else {
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
