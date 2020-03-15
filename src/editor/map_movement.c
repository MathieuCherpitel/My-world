/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_movement
*/


#include "include_structs.h"
#include "include_editor.h"
#include "my_world.h"

void move_up(sfVector2f **map, int size, int sens)
{
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++) {
            map[y][x].y -= sens + 1;
            map[y][x].x -= sens + 1;
        }
}

void move_down(sfVector2f **map, int size, int sens)
{
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++) {
            map[y][x].y += sens + 1;
            map[y][x].x += sens + 1;
        }
}

void move_left(sfVector2f **map, int size, int sens)
{
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++) {
            map[y][x].x -= sens + 1;
            map[y][x].y += sens + 1;
        }

}

void move_right(sfVector2f **map, int size, int sens)
{
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++) {
            map[y][x].x += sens + 1;
            map[y][x].y -= sens + 1;
        }
}