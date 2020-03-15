/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** handler tools buttons
*/

#include "my_world.h"
#include "include_structs.h"

int demote_editor_button(game_data_t *game_data)
{
    game_data->scenes[EDITOR_SCENE]->buttons[3]->selected = TRUE;
    game_data->scenes[EDITOR_SCENE]->buttons[4]->selected = FALSE;
    game_data->scenes[EDITOR_SCENE]->buttons[5]->selected = FALSE;
    game_data->editor_data->current_tool = RESET;
    return (EDITOR_SCENE);
}

int scale_editor_button(game_data_t *game_data)
{
    game_data->scenes[EDITOR_SCENE]->buttons[4]->selected = TRUE;
    game_data->scenes[EDITOR_SCENE]->buttons[3]->selected = FALSE;
    game_data->scenes[EDITOR_SCENE]->buttons[5]->selected = FALSE;
    game_data->editor_data->current_tool = ALTITUDE;
    return (EDITOR_SCENE);
}

int paint_editor_button(game_data_t *game_data)
{
    game_data->scenes[EDITOR_SCENE]->buttons[5]->selected = TRUE;
    game_data->scenes[EDITOR_SCENE]->buttons[3]->selected = FALSE;
    game_data->scenes[EDITOR_SCENE]->buttons[4]->selected = FALSE;
    game_data->editor_data->current_tool = PAINT;
    return (EDITOR_SCENE);
}