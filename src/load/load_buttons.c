/*
** EPITECH PROJECT, 2020
** load buttons
** File description:
** load every buttons (each buttons is in an array of 3 sprites)
*/

#include "my_world.h"
#include "include_structs.h"
#include <stdlib.h>

sfSprite **set_sprites_from_rect(sfSprite **sprite_array, sfTexture *texture,
                                                            sfIntRect rect)
{
    int count = 0;

    while (count < 3) {
        sprite_array[count] = sfSprite_create();
        sfSprite_setTexture(sprite_array[count], texture, sfFalse);
        sfSprite_setTextureRect(sprite_array[count], rect);
        count++;
        rect.left += 180;
    }
    sprite_array[count] = NULL;
    return (sprite_array);
}

loaded_sprites_t *set_sprite_array(loaded_sprites_t *loaded_sprites,
                                            sfTexture *texture, sfIntRect rect)
{
    loaded_sprites = malloc(sizeof(loaded_sprites_t));
    loaded_sprites->sprites = malloc(sizeof(sfSprite *) * (4));
    if (loaded_sprites == NULL || loaded_sprites->sprites == NULL)
        return (NULL);
    loaded_sprites->sprites = set_sprites_from_rect(loaded_sprites->sprites,
                                                                texture, rect);
    return (loaded_sprites);
}

window_data_t * load_buttons(window_data_t *window_data)
{
    int count = 10;
    sfIntRect rect = {.left = 0, .top = -8, .width = 180, .height = 185};

    while (count < BUTTON_COUNT + 10) {
        window_data->loaded_sprites[count] = set_sprite_array
        (window_data->loaded_sprites[count], window_data->loaded_sprites
                                                    [BUTTON]->texture, rect);
        if (window_data->loaded_sprites[count] == NULL)
            return (NULL);
        rect.left = 0;
        rect.top += 29;
        rect.top += 187;
        count++;
    }
    return (window_data);
}