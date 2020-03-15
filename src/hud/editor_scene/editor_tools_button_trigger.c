/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** tool button trigger
*/

#include "my_world.h"
#include "include_structs.h"

void button_editor_demote(window_data_t *window_data)
{
    window_data->button_click_id = DEMOTE_EDITOR;
}

void button_editor_scale(window_data_t *window_data)
{
    window_data->button_click_id = SCALE_EDITOR;
}

void button_editor_paint(window_data_t *window_data)
{
    window_data->button_click_id = PAINT_EDITOR;
}
