/*
** EPITECH PROJECT, 2020
** button handler
** File description:
** handle buttons for load map scene
*/

#include "my_world.h"
#include "include_structs.h"

void button_load(window_data_t *window_data)
{
    window_data->button_click_id = LOAD;
}

void button_new(window_data_t *window_data)
{
    window_data->button_click_id = NEW;
}

void button_quit(window_data_t *window_data)
{
    window_data->button_click_id = QUIT;
}