/*
** EPITECH PROJECT, 2020
** parse save file
** File description:
** save file parser
*/

#include <fcntl.h>
#include <stdio.h>
#include "include_structs.h"
#include "include_hud.h"
#include "my_world.h"

editor_data_t *get_sprites_textures(FILE *file,
                        editor_data_t *editor_data, game_data_t *game_data)
{
    size_t read_size = 10;
    char *buffer = NULL;

    getline(&buffer, &read_size, file);
    editor_data->background = game_data->window_data->loaded_sprites
                                            [my_getnbr(buffer)]->sprites[0];
    getline(&buffer, &read_size, file);
    editor_data->texture_set = game_data->window_data->loaded_sprites
                                                [my_getnbr(buffer)]->texture;
    getline(&buffer, &read_size, file);
    editor_data->size = my_getnbr(buffer);
    return (editor_data);
}

FILE *read_save_file(char *filepath)
{
    FILE *file = fopen(filepath, "r");

    if (file == NULL)
        return (NULL);
    return (file);
}

editor_data_t *parse_save_file(game_data_t *game_data)
{
    FILE *file = read_save_file("maps/save1.map");

    if (file == NULL)
        return (NULL);
    game_data->editor_data = get_sprites_textures(file,
                                        game_data->editor_data, game_data);
    game_data->editor_data = get_editor_map(file, game_data->editor_data);
    fclose(file);
    return (game_data->editor_data);
}