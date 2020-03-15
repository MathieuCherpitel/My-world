/*
** EPITECH PROJECT, 2020
** button handler 2
** File description:
** handle more buttons from new scene
*/

#include "my_world.h"
#include "include_structs.h"

int set_background_blue(game_data_t *game_data)
{
    game_data->editor_data->background_selected_index = BACKGROUND_BLUE;
    game_data->editor_data->background = game_data->window_data->loaded_sprites
                                                [BACKGROUND_BLUE]->sprites[0];
    return (NEW_SCENE);
}

int set_background_white(game_data_t *game_data)
{
    game_data->editor_data->background_selected_index = BACKGROUND_WHITE;
    game_data->editor_data->background = game_data->window_data->loaded_sprites
                                                [BACKGROUND_WHITE]->sprites[0];
    return (NEW_SCENE);
}

int set_texture_1(game_data_t *game_data)
{
    game_data->editor_data->texture_selected_index = TEXTURE_1;
    game_data->editor_data->texture_set = game_data->window_data->loaded_sprites
                                                        [TEXTURE_1]->texture;
    return (NEW_SCENE);
}

int set_texture_2(game_data_t *game_data)
{
    game_data->editor_data->texture_selected_index = TEXTURE_2;
    game_data->editor_data->texture_set = game_data->window_data->loaded_sprites
                                                        [TEXTURE_2]->texture;
    return (NEW_SCENE);
}