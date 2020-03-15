/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** create editor game oj
*/

#include "my_world.h"
#include "include_structs.h"
#include "include_hud.h"

static sfText **set_text(game_objects_t *game_objects, game_data_t *game_data)
{
    game_objects->text[0] = init_text(game_data->window_data->fonts[RALEWAY],
                                                "Tool radius", sfWhite, 40);
    game_objects->text[0] = edit_text(game_objects->text[0], 1600, 20);
    game_objects->text[1] = init_text(game_data->window_data->fonts[RALEWAY],
                    my_itoa(game_data->editor_data->tool_radius), sfWhite, 40);
    game_objects->text[1] = edit_text(game_objects->text[1], 1820, 55);
    game_objects->text[2] = init_text(game_data->window_data->fonts[RALEWAY],
                                            "Move sensitivity", sfWhite, 40);
    game_objects->text[2] = edit_text(game_objects->text[2], 1570, 180);
    game_objects->text[3] = init_text(game_data->window_data->fonts[RALEWAY],
                    my_itoa(game_data->editor_data->move_sens), sfWhite, 40);
    game_objects->text[3] = edit_text(game_objects->text[3], 1820, 215);
    game_objects->text[4] = init_text(game_data->window_data->fonts[RALEWAY],
                                        "Altitude sensitivity", sfWhite, 40);
    game_objects->text[4] = edit_text(game_objects->text[4], 1550, 340);
    game_objects->text[5] = init_text(game_data->window_data->fonts[RALEWAY],
                    my_itoa(game_data->editor_data->move_sens), sfWhite, 40);
    game_objects->text[5] = edit_text(game_objects->text[5], 1820, 375);
    return (game_objects->text);
}

game_objects_t *create_editor_game_objects(game_objects_t *game_objects,
                                                    game_data_t *game_data)
{
    game_data->editor_data->tool_radius = 1;
    game_data->editor_data->move_sens = 1;
    game_objects->textures[0] = game_data->window_data->loaded_sprites
                                                        [TEXTURE_1]->texture;
    game_objects->textures[1] = game_data->window_data->loaded_sprites
                                                        [TEXTURE_2]->texture;
    game_objects->sprites[0] = NULL;
    game_objects->animated_sprites[0] = NULL;
    game_objects->text[6] = NULL;
    game_objects->music = game_data->window_data->musics[LOADING_SCENE];
    game_objects->text = set_text(game_objects, game_data);
    return (game_objects);
}