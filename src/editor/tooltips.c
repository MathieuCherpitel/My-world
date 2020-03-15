/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** tooltips
*/

#include "include_structs.h"
#include "include_editor.h"
#include "my_world.h"

static void change_tooltip(sfVector2i pos, game_data_t *game_data, char *str)
{
    sfText_setString(EDITOR tooltip, str);
    sfText_setPosition(EDITOR tooltip, (sfVector2f)
    {.x = pos.x - 20, .y = pos.y + 20});
    sfRenderWindow_drawText(game_data->window_data->window,
    EDITOR tooltip, NULL);
}

void show_tooltips(game_data_t *game_data)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow
    (game_data->window_data->window);

    if (pos.y > 7 && pos.x > 103 && pos.x < 189 && pos.y < 91)
        change_tooltip(pos, game_data, "Save current map.");
    else if (pos.y > 7 && pos.x > 400 && pos.x < 487 && pos.y < 91)
        change_tooltip(pos, game_data, "Elevation tool (use both clicks).");
    if (pos.y > 7 && pos.x > 500 && pos.x < 587 && pos.y < 91)
        change_tooltip(pos, game_data, "Reset vertex tool.");
    else if (pos.y > 7 && pos.x > 600 && pos.x < 687 && pos.y < 91)
        change_tooltip(pos, game_data,
        "Texture painter tool (use both clicks).");
}