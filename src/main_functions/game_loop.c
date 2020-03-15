/*
** EPITECH PROJECT, 2020
** game loop
** File description:
** main loop of the game
*/

#include "my_world.h"
#include "include_structs.h"
#include "include_hud.h"
#include "include_scenes.h"
#include "include_main_functions.h"
#include <stdlib.h>

// since game data is defined after button, we had to change the id of
// an int in window data and with this id call the correct
// function with game_data as parameter

func_ptr_t *ptr_func(func_ptr_t *index)
{
    index[NONE] = &none_button;
    index[NEW] = &new_button;
    index[LOAD] = &load_button;
    index[QUIT] = &quit_button;
    index[RETURN] = &return_button;
    index[CREATE] = &create_button;
    index[SET_TEXTURE_1] = &set_texture_1;
    index[SET_TEXTURE_2] = &set_texture_2;
    index[SET_BACKGROUND_WHITE] = &set_background_white;
    index[SET_BACKGROUND_BLUE] = &set_background_blue;
    index[SIZE] = &size_slider_button;
    index[EXIT_EDITOR] = &exit_editor_button;
    index[SAVE_EDITOR] = &save_editor_button;
    index[RADIUS_EDITOR] = &radius_slider_button;
    index[DEMOTE_EDITOR] = &demote_editor_button;
    index[SCALE_EDITOR] = &scale_editor_button;
    index[PAINT_EDITOR] = &paint_editor_button;
    index[MOVE_SENS] = &move_sens_slider_button;
    index[alt_sens] = &alt_sens_slider_button;
    return (index);
}

void init_game_loop(game_data_t *game_data)
{
    game_data->window_data->button_click_id = NONE;
    game_data->editor_data->texture_selected_index = TEXTURE_1;
    game_data->editor_data->background_selected_index = BACKGROUND_BLUE;
    game_data->editor_data->background = game_data->window_data->loaded_sprites
                                                [BACKGROUND_BLUE]->sprites[0];
    game_data->editor_data->tool_radius = 1;
    game_data->editor_data->texture_set = game_data->window_data->
                                            loaded_sprites[TEXTURE_1]->texture;
    game_data->current_scene = LOADING_SCENE;
}

int game_loop(game_data_t *game_data)
{
    int scene_index = LOADING_SCENE;
    func_ptr_t *index_ptr = malloc(sizeof(func_ptr_t) * (18));
    index_ptr = ptr_func(index_ptr);

    init_game_loop(game_data);
    while (sfRenderWindow_isOpen(game_data->window_data->window)) {
        draw_scene(game_data, scene_index);
        game_data->scenes[scene_index]->input_manager
                    (game_data->scenes[scene_index], game_data->window_data);
        check_buttons(game_data->scenes[scene_index], game_data);
        scene_index = index_ptr
                        [game_data->window_data->button_click_id](game_data);
        game_data->window_data->button_click_id = NONE;
        sfRenderWindow_display(game_data->window_data->window);
        scene_index = state_machine(scene_index);
        game_data->current_scene = scene_index;
    }
    free_window_data(game_data->window_data);
    free_scenes(game_data);
    return (0);
}