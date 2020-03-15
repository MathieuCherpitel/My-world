/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** get map from save1.map file
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_world.h"
#include "include_structs.h"

int *get_map_line(int *line, char *buffer, int size)
{
    int count = 0;
    char **char_tab = my_str_to_word_array(buffer, " ");

    while (count < size) {
        line[count] = my_getnbr(char_tab[count]);
        count++;
    }
    return (line);
}

int **map_to_array(char *buffer, int size, int **map, FILE *file)
{
    int count = 0;
    size_t read_size = 10;

    while (count < size) {
        getline(&buffer, &read_size, file);
        map[count] = get_map_line(map[count], buffer, size);
        if (map[count] == NULL)
            return (NULL);
        count++;
    }
    return (map);
}

char *get_to_map(FILE *file)
{
    size_t read_size = 10;
    char *buffer = NULL;
    int count = 0;

    while (count < 3) {
        getline(&buffer, &read_size, file);
        count++;
    }
    getline(&buffer, &read_size, file);
    return (buffer);
}

int **allocate_map(int size)
{
    int **map = malloc(sizeof(int *) * (size + 1));
    int count = 0;

    if (map == NULL)
        return (NULL);
    while (count < size) {
        map[count] = malloc(sizeof(int) * size);
        if (map[count] == NULL)
            return (NULL);
        count++;
    }
    map[count] = NULL;
    return (map);
}

editor_data_t *get_editor_map(FILE *file, editor_data_t *editor_data)
{
    char *buffer = get_to_map(file);

    editor_data->map = allocate_map(editor_data->size);
    if (editor_data->map == NULL)
        return (NULL);
    editor_data->map = map_to_array(buffer, editor_data->size,
                                                editor_data->map, file);
    return (editor_data);
}