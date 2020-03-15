/*
** EPITECH PROJECT, 2020
** trigger buttons
** File description:
** more trigger functions for new scene
*/

#include "my_world.h"
#include "include_structs.h"

void button_background_blue(window_data_t *window_data)
{
    window_data->button_click_id = SET_BACKGROUND_BLUE;
}

void button_background_white(window_data_t *window_data)
{
    window_data->button_click_id = SET_BACKGROUND_WHITE;
}

void button_texture_1(window_data_t *window_data)
{
    window_data->button_click_id = SET_TEXTURE_1;
}

void button_texture_2(window_data_t *window_data)
{
    window_data->button_click_id = SET_TEXTURE_2;
}