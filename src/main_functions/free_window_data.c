/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** free window data
*/

#include <stdlib.h>
#include "my_world.h"
#include "include_structs.h"

static void destroy_assets(loaded_sprites_t **loaded_sprites)
{
    int count = 0;
    int sprite_count = 0;

    while (count < 45) {
        while (loaded_sprites[count]->sprites[sprite_count] != NULL) {
            sfSprite_destroy(loaded_sprites[count]->sprites[sprite_count]);
            sprite_count++;
        }
        free(loaded_sprites[count]->sprites);
        free(loaded_sprites[count]);
        count++;
    }
}

void free_window_data(window_data_t *window_data)
{
    destroy_assets(window_data->loaded_sprites);
    sfFont_destroy(window_data->fonts[RALEWAY]);
    sfMusic_stop(window_data->musics[LOADING_MUSIC]);
    sfMusic_destroy(window_data->musics[LOADING_MUSIC]);
    free(window_data->fonts);
    free(window_data->musics);
}