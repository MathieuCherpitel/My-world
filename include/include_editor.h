/*
** EPITECH PROJECT, 2020
** include file
** File description:
** editor directory include
*/

#ifndef _EDITOR_H
#define _EDITOR_H

#include "include_structs.h"

// int editor(window_data_t *window_data, int **map);
void draw_editor(game_data_t *game_data_t);

// inputzer
void editor_input_manager(scenes_t *scene, window_data_t *window);

// includes for computing.c
sfVector2f **get_map(int size);
sfVector2f **create_map(int **iso_map, int size);
sfVector2f  project_iso_point(int x, int y, int z);
int **set_map(int size);

// includes for hard inputs
void check_hard_inputs(game_data_t *data);

//includes for move.c
void move_up(sfVector2f **map, int size, int sens);
void move_down(sfVector2f **map, int size, int sens);
void move_left(sfVector2f **map, int size, int sens);
void move_right(sfVector2f **map, int size, int sens);

//includes for various tools
void texture_tool(game_data_t *game_data);
void show_tooltips(game_data_t *game_data);
void altitude_tool(game_data_t *game_data);
void reset_tool(game_data_t *game_data);

#endif /* !_EDITOR_H */