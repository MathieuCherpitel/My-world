/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_computing
*/

#include <math.h>
#include <stdlib.h>
#include "my_world.h"
#include "include_structs.h"
#include "include_editor.h"

int **set_map(int size)
{
    int **map = malloc(sizeof(int *) * size);

    for (int i = 0; i < size; i++) {
        map[i] = malloc(4 * size);
        for (int j = 0; j < size; j++)
                map[i][j] = 1;
    }
    return map;
}

sfVector2f project_iso_point(int x, int y, int z)
{
    sfVector2f point;

    point.x = cos(0.25 * M_PI) * x - cos(0.25 * M_PI) * y;
    point.y = sin((7 * M_PI) / 36) * y + sin((7 * M_PI) / 36) * x - z;
    return point;
}

sfVector2f **create_map(int **iso_map, int size)
{
    sfVector2f **map = malloc(sizeof(sfVector2f) * (size + 1));
    int y_sample = 0;
    int x_sample = 0;

    for (int i = 0; i < size; i++)
        map[i] = malloc(sizeof(sfVector2f) * size + 1);
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            map[y][x] = project_iso_point(
            x + x_sample, y + y_sample, iso_map[y][x] * 8);
            x_sample += 32;
        }
        x_sample = 0;
        y_sample += 32;
    }
    return map;
}

sfVector2f **get_map(int size)
{
    int x_offset = 960;
    int y_offset = 540 - (size * 16);

    int **iso_map = set_map(size);
    sfVector2f **map = create_map(iso_map, size);
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size ; x++) {
            map[y][x].x += x_offset;
            map[y][x].y += y_offset;
        }
    return map;
}