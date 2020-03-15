/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** create slide button
*/

#include "my_world.h"
#include "include_structs.h"

// the slider is 180 pixels long
void init_slider_button(button_t *button, sfVector2f position,
                                                    game_data_t *game_data)
{
    button->button_type = SLIDER;
    button->slider.slider_bar = sfSprite_create();
    button->slider.slider_button = sfSprite_create();
    button->slider.slider_bar = sfSprite_copy
            (game_data->window_data->loaded_sprites[SLIDER_BAR]->sprites[0]);
    button->slider.slider_button = sfSprite_copy
        (game_data->window_data->loaded_sprites[SLIDER_HANDLER]->sprites[0]);
    button->slider.left_position = position;
    button->slider.right_position = (sfVector2f)
                                    {.x = position.x + 180, .y = position.y};
    sfSprite_setPosition(button->slider.slider_bar, position);
    position.x += 90;
    position.y -= 7;
    sfSprite_setPosition(button->slider.slider_button, position);
    button->tool_button = FALSE;
    button->selected = FALSE;
}
