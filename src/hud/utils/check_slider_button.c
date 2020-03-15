/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** check if slider button is triggeres and replace hitbox
*/

#include "my_world.h"
#include "include_structs.h"

void check_slider_button(button_t *button, sfVector2f mouse_position,
                                                    game_data_t *game_data)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(button->slider.slider_bar);
    bounds.height += 70;
    bounds.top -= 20;

    if (sfFloatRect_contains
                (&bounds, mouse_position.x, mouse_position.y) == sfTrue) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            button->callback(game_data->window_data);
        }
    }
}
