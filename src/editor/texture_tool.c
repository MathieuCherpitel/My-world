/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** texture_tool
*/

#include "include_structs.h"
#include "include_editor.h"
#include "my_world.h"

static void radius_two(game_data_t *game_data, int factor, int x, int y)
{
    EDITOR texture[y][x] = factor;
    if (x - 1 > 0 && y - 1 > 0)
        EDITOR texture[y - 1][x - 1] = factor;
    if (x < EDITOR size - 1 && y - 1 > 0)
        EDITOR texture[y - 1][x] = factor;
    if (x + 1 < EDITOR size - 1 && y - 1 > 0)
        EDITOR texture[y - 1][x + 1] = factor;
    if (y < EDITOR size - 1 && x - 1 > 0)
        EDITOR texture[y][x - 1] = factor;
    if (y < EDITOR size - 1 && x + 1 < EDITOR size - 1)
        EDITOR texture[y][x + 1] = factor;
    if (x - 1 > 0 && y + 1 < EDITOR size - 1)
        EDITOR texture[y + 1][x - 1] = factor;
    if (x < EDITOR size - 1 && y + 1 < EDITOR size - 1)
        EDITOR texture[y + 1][x] = factor;
    if (x + 1 < EDITOR size - 1 && y + 1 < EDITOR size)
        EDITOR texture[y + 1][x + 1] = factor;
}

static void action(game_data_t *game_data, int factor, int x, int y)
{
    switch (EDITOR tool_radius) {
        case (2):
            radius_two(game_data, factor, x, y);
            break;
        default:
            EDITOR texture[y][x] = factor;
            break;
    }
}

static void click(game_data_t *game_data, int factor)
{
    sfVector2i pos;

    pos = sfMouse_getPositionRenderWindow(game_data->window_data->window);
    for (int y = 0; y < EDITOR size; y++) {
        for (int x = 0; x < EDITOR size; x++)
            if (pos.x <= EDITOR vector_map[y][x].x + 12
            && (pos.x >= EDITOR vector_map[y][x].x - 12)
            && (pos.y <= EDITOR vector_map[y][x].y + 12)
            && (pos.y >= EDITOR vector_map[y][x].y - 12))
                action(game_data, factor, x, y);
    }
}

void texture_tool(game_data_t *game_data)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        click(game_data, -1);
    if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue)
        click(game_data, 1);
}