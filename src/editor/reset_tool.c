/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** reset_tool
*/

#include "include_structs.h"
#include "include_editor.h"
#include "my_world.h"

static void click(game_data_t *game_data)
{
    sfVector2i pos;

    pos = sfMouse_getPositionRenderWindow(game_data->window_data->window);
    for (int y = 0; y < EDITOR size; y++) {
        for (int x = 0; x < EDITOR size; x++)
            if (pos.x <= EDITOR vector_map[y][x].x + 13
            && (pos.x >= EDITOR vector_map[y][x].x - 13)
            && (pos.y <= EDITOR vector_map[y][x].y + 13)
            && (pos.y >= EDITOR vector_map[y][x].y - 13))
                EDITOR vector_map[y][x].y =
                x + y + 300 + (16 * x) + (16 * y);
    }
}

void reset_tool(game_data_t *game_data)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        click(game_data);
}