/*
** EPITECH PROJECT, 2020
** include file
** File description:
** include functions from hud folder
*/

#ifndef _HUD_H
#define _HUD_H

// include structs
#include <stdio.h>
#include "include_structs.h"


//                  UTILS   (in directory utils)

// include functions from button
int check_buttons(scenes_t *scene, game_data_t *game_data);
void is_button_clicked(button_t *button, sfVector2f mouse_position,
                                                game_data_t *game_data);
void check_rectangle_button(button_t *button, sfVector2f mouse_position,
                                                game_data_t *game_data);
void check_sprite_button(button_t *button, sfVector2f mouse_position,
                                                game_data_t *game_data);

// include functions from create rectangle button
void init_rectangle_button(button_t *button, sfVector2f position,
                                                        sfVector2f size);
void edit_rectangle_button(button_t *button, sfColor idle, sfColor hover,
                                                            sfColor click);

// include function from create sprite button
void init_sprite_button(button_t *button, sfVector2f position, sfVector2f size,
                                                        sfSprite **sprite);

// include from create slider button
void init_slider_button(button_t *button, sfVector2f position,
                                                    game_data_t *game_data);

// include functions from create text
sfText *init_text(sfFont *font, char *string, sfColor color, int size);
sfText *edit_text(sfText *text, int x, int y);

// include function from check slider button
void check_slider_button(button_t *button, sfVector2f mouse_position,
                                                    game_data_t *game_data);

//                BUTTONS HANDLERS AND TRIGGERS


//               LOAD MAP SCENE (in directiry load map scene)
// button triggers :
void button_quit(window_data_t *window_data);
void button_new(window_data_t *window_data);
void button_load(window_data_t *window_data);
editor_data_t *parse_save_file(game_data_t *game_data);
FILE *read_save_file(char *filepath);
editor_data_t *get_sprites_textures(FILE *file, editor_data_t *editor_data,
                                                        game_data_t *game_data);
editor_data_t *get_editor_map(FILE *file, editor_data_t *editor_data);
int **allocate_map(int size);
char *get_to_map(FILE *file);

// buttons handlers
int quit_button(game_data_t *game_data);
int load_button(game_data_t *game_data);
int new_button(game_data_t *game_data);
int none_button(game_data_t *game_data);

//              NEW SCENE   (in directory new scene)
// buttons triggers
void button_new_return(window_data_t *window_data);
void button_new_create(window_data_t *window_data);
void button_texture_2(window_data_t *window_data);
void button_texture_1(window_data_t *window_data);
void button_background_blue(window_data_t *window_data);
void button_background_white(window_data_t *window_data);
void button_slider_size(window_data_t *window_data);
void button_editor_return(window_data_t *window_data);
void button_editor_save(window_data_t *window_data);
void button_editor_radius(window_data_t *window_data);
void button_editor_demote(window_data_t *window_data);
void button_editor_scale(window_data_t *window_data);
void button_editor_paint(window_data_t *window_data);
void button_editor_move_sens(window_data_t *window_data);
void button_editor_alt_sens(window_data_t *window_data);

// buttons handlers
int return_button(game_data_t *game_data);
int create_button(game_data_t *game_data);
int set_texture_2(game_data_t *game_data);
int set_texture_1(game_data_t *game_data);
int set_background_white(game_data_t *game_data);
int set_background_blue(game_data_t *game_data);
int size_slider_button(game_data_t *game_data);
int exit_editor_button(game_data_t *game_data);
int save_editor_button(game_data_t *game_data);
int radius_slider_button(game_data_t *game_data);
int demote_editor_button(game_data_t *game_data);
int scale_editor_button(game_data_t *game_data);
int paint_editor_button(game_data_t *game_data);
int move_sens_slider_button(game_data_t *game_data);
int alt_sens_slider_button(game_data_t *game_data);

#endif /* !_HUD_H */
