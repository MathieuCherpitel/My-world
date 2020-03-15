/*
** EPITECH PROJECT, 2020
** include file
** File description:
** include functions from main functions folder
*/

#ifndef _MAIN_FUNCTIONS_H
#define _MAIN_FUNCTIONS_H

// struct include
#include "include_structs.h"

// game loop functions include
int game_loop(game_data_t *game_data);
func_ptr_t* ptr_func(func_ptr_t *index);

// main function include
int main(int ac, __attribute__((unused)) char **av);

// my world functions include
int my_world(void);
window_data_t *init_render_window(window_data_t *window_data);
int destroy(window_data_t *window_data);

// state machine function include
int state_machine(int scene_index);
int check_load_map_state(void);
int check_loading_state(void);

// usage function include
void usage(void);

// free scenes functions include
void free_scenes(game_data_t *game_data);

// free window data function include
void free_window_data(window_data_t *window_data);

#endif /* !_MAIN_FUNCTIONS_H */
