/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** free scenes
*/

#include <stdlib.h>
#include "my_world.h"
#include "include_structs.h"

void free_text(scenes_t *scene)
{
    int count = 0;

    while (scene->game_objects->text[count] != NULL) {
        sfText_destroy(scene->game_objects->text[count]);
        count++;
    }
}

void free_buttons(scenes_t *scene)
{
    int count = 0;

    while (scene->buttons[count] != NULL) {
        free(scene->buttons[count]);
        count++;
    }
}

void free_scenes(game_data_t *game_data)
{
    int count = 0;

    while (count < 4) {
        free_buttons(game_data->scenes[count]);
        free_text(game_data->scenes[count]);
        free(game_data->scenes[count]->game_objects);
        count++;
    }
}