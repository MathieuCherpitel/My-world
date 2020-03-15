/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** create sprite buttons
*/

#include "my_world.h"
#include "include_structs.h"
#include <stdlib.h>

void init_sprite_button(button_t *button, sfVector2f position,
                                sfVector2f size, sfSprite **sprite)
{
    int count = 0;

    button->button_type = SPRITE;
    button->sprites = malloc(sizeof(sfSprite *) * 3);
    while (count < 3) {
        button->button_type = SPRITE;
        button->sprites[count] = sprite[count];
        sfSprite_setPosition(button->sprites[count], position);
        sfSprite_setScale(button->sprites[count], size);
        count++;
    }
    button->sprite_to_draw = button->sprites[0];
    button->tool_button = FALSE;
    button->selected = FALSE;
}