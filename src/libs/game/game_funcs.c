#include "game_funcs.h"

int loadAssets(*game_assets, xpm_map_t* arr[][]){

    int res;

    for (int i = 0; i < GAME_ASSETS_ARR_SIZE; i++){

        if (i == 0)
            res = vg_load_sprites(arr[0], ARRAY_SIZE(arr[i]), BTNS);

        else if  (i == 1)
            res = vg_load_sprites(arr[1], ARRAY_SIZE(arr[i]), BGS);

        else if (i == 2)
            res = vg_load_sprites(arr[2], ARRAY_SIZE(arr[i]), PIECES);

        else if (i == 3)
            res = vg_load_sprites(arr[3], ARRAY_SIZE(arr[i]), BORDERS);

        else if (i == 4)
            res = vg_load_sprites(arr[4], ARRAY_SIZE(arr[i]), CHARS);

        else if (i == 5)
            res = vg_load_sprites(arr[5], ARRAY_SIZE(arr[i]), LOGOS);

        else
            res = vg_load_sprites(arr[6], ARRAY_SIZE(arr[i]), V_FX);


        if (res != EXIT_SUCCESS)
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


