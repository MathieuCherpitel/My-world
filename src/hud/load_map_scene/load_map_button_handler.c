/*
** EPITECH PROJECT, 2020
** button handler
** File description:
** handle
*/

#include "my_world.h"
#include "include_structs.h"
#include "include_hud.h"
#include <stdio.h>

int none_button(game_data_t *game_data)
{
    return (game_data->current_scene);
}

int new_button(game_data_t *game_data)
{
    game_data->current_scene = NEW_SCENE;
    return (NEW_SCENE);
}

int load_button(game_data_t *game_data)
{
    game_data->current_scene = EDITOR_SCENE;
    game_data->editor_data = parse_save_file(game_data);
    game_data->editor_data->map = NULL;
    return (EDITOR_SCENE);
}

int quit_button(game_data_t *game_data)
{
    sfRenderWindow_close(game_data->window_data->window);
    return (QUIT);
}