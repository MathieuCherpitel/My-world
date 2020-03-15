/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** slider trigger
*/

#include "include_structs.h"
#include "my_world.h"

void button_editor_move_sens(window_data_t *window_data)
{
    window_data->button_click_id = MOVE_SENS;
}

void button_editor_alt_sens(window_data_t *window_data)
{
    window_data->button_click_id = alt_sens;
}