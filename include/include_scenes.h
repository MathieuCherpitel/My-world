/*
** EPITECH PROJECT, 2020
** include file
** File description:
** include for menu directory
*/

#ifndef _SCENES_H
#define _MENU_H

// struct include
#include "include_structs.h"

//                                  SCENES INCLUDES

//  EDITOR SCENE
// buttons

// scene
scenes_t *create_editor_scene(scenes_t *scene, game_data_t *game_data);

// game objects
game_objects_t *create_editor_game_objects(game_objects_t *game_objects,
                                                    game_data_t *game_data);
//  LOAD MAP SCENE
// buttons
button_t **create_load_map_buttons(scenes_t *scene);
button_t **set_load_map_buttons_handler(scenes_t *scene);

// scene
scenes_t *create_load_map_scene(scenes_t *scene, game_data_t *game_data);
void loading_map_input_manager(scenes_t *scene, window_data_t *window_data);


//  LOADING SCENE
// scene
scenes_t *create_loading_scene(scenes_t *scene, game_data_t *game_data);
void loading_input_manager(scenes_t *scene, window_data_t *window_data);
void text_animation(scenes_t *scene);

// MENU SCENE
// buttons

// scene
scenes_t *create_menu_scene(scenes_t *scene, game_data_t *game_data);

// NEW SCENE
// buttons
button_t **create_new_buttons(scenes_t *scene, game_data_t *game_data);
button_t **set_new_buttons_handler(scenes_t *scene);

// game objects
game_objects_t *create_new_game_objects(game_objects_t *game_objects,
                                                    game_data_t *game_data);

// scene
scenes_t *create_new_scene(scenes_t *scene, game_data_t *game_data);
void new_input_manager(scenes_t *scene, window_data_t *window_data);
scenes_t *change_preview_place(scenes_t *scene);

// NEW SCENE
// buttons
button_t **create_editor_buttons(scenes_t *scene, game_data_t *game_data);
button_t **set_editor_buttons_handler(scenes_t *scene);

// scene
scenes_t *create_editor_scene(scenes_t *scene, game_data_t *game_data);
void editor_input_manager(scenes_t *scene, window_data_t *window_data);
scenes_t *change_preview_place(scenes_t *scene);


//  UTILS
// create scene
game_data_t *create_scenes(game_data_t *game_data);
button_t **allocate_buttons(scenes_t *scene, int button_count);

// draw scene
void draw_scene(game_data_t *game_data, int scene_index);
void draw_game_objects(game_objects_t *game_objects,
                                                window_data_t *window_data);
void draw_buttons(button_t **buttons, window_data_t *window_data);
void draw_text(game_objects_t *game_objects, window_data_t *window_data);

// draw special
void draw_specific_scene_animation(game_data_t *game_data, int scene_index);
void draw_selected_background(game_data_t *game_data);
void draw_selected_texture(game_data_t *game_data);
void draw_special(game_data_t *game_data, int scene_index);


#endif /* !_SCENES_H */
