/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** check_hard_inputs
*/

#include "include_structs.h"
#include "include_editor.h"
#include "my_world.h"

void check_tool_inputs(UNUSED game_data_t *data, UNUSED sfKeyCode code)
{
    return;
}

void check_hard_inputs(game_data_t *game_data)
{
    if (game_data->window_data->event.type == sfEvtKeyPressed) {
        switch (game_data->window_data->event.key.code) {
            case (sfKeyUp):
            move_up(EDITOR vector_map, EDITOR size, EDITOR move_sens);
            break;
            case (sfKeyDown):
            move_down(EDITOR vector_map, EDITOR size, EDITOR move_sens);
            break;
            case (sfKeyLeft):
            move_left(EDITOR vector_map, EDITOR size, EDITOR move_sens);
            break;
            case (sfKeyRight):
            move_right(EDITOR vector_map, EDITOR size, EDITOR move_sens);
            break;
            default:
            check_tool_inputs
            (game_data, game_data->window_data->event.key.code);
        }
    }
}