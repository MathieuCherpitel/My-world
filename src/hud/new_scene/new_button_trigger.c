/*
** EPITECH PROJECT, 2020
** trigger
** File description:
** trigger handler for load scene
*/

#include "my_world.h"
#include "include_structs.h"

void button_slider_size(window_data_t *window_data)
{
    window_data->button_click_id = SIZE;
}

void button_new_create(window_data_t *window_data)
{
    window_data->button_click_id = CREATE;
}

void button_new_return(window_data_t *window_data)
{
    window_data->button_click_id = RETURN;
}