/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_editor
*/

#include <stdlib.h>
#include "include_structs.h"
#include "include_scenes.h"
#include "include_editor.h"
#include "my_world.h"

sfVertexArray *get_map_vertices(sfVector2f **map, int **texture, int size)
{
    sfVertexArray *arr = sfVertexArray_create();

    for (int y = 0; y < size - 1; y++) {
        for (int x = size - 1; x > 0; x--) {
                sfVertexArray_append(arr, ((sfVertex){.texCoords =
texture[y][x] == 1 ? (sfVector2f){.y = 200, .x = 0} : (sfVector2f){.y = 200,
.x = 200}, .color = sfWhite, .position = map[y + 1][x - 1]}));
                sfVertexArray_append(arr, ((sfVertex){.texCoords =
texture[y][x] == 1 ? (sfVector2f){.y = 0, .x = 0} : (sfVector2f){.y = 0,
.x = 200}, .color = sfWhite, .position = map[y][x - 1]}));
                sfVertexArray_append(arr, ((sfVertex){.texCoords =
texture[y][x] == 1 ? (sfVector2f){.y = 0, .x = 200} : (sfVector2f){.y = 0,
.x = 400}, .color = sfWhite, .position = map[y][x]}));
                sfVertexArray_append(arr, ((sfVertex){.texCoords =
texture[y][x] == 1 ? (sfVector2f){.y = 200, .x = 200} : (sfVector2f){.y = 200,
.x = 400}, .color = sfWhite, .position = map[y + 1][x]}));
        }
    }
    sfVertexArray_setPrimitiveType(arr, sfQuads);
    return arr;
}

void draw_map(game_data_t *game_data)
{
    sfVertexArray *arr = get_map_vertices(EDITOR vector_map,
    EDITOR texture, EDITOR size);
    sfRenderStates *state = malloc(sizeof(sfRenderStates));

    state->texture = EDITOR texture_set;
    state->blendMode = sfBlendAlpha;
    state->transform = sfTransform_Identity;
    state->shader = NULL;
    sfRenderWindow_drawSprite(game_data->window_data->window,
    EDITOR background, NULL);
    draw_buttons(game_data->scenes[EDITOR_SCENE]->buttons,
    game_data->window_data);
    draw_text(game_data->scenes[EDITOR_SCENE]->game_objects,
    game_data->window_data);
    sfRenderWindow_drawVertexArray(game_data->window_data->window, arr, state);
}

void check_tools_input(game_data_t *game_data)
{
    switch (EDITOR current_tool) {
        case (ALTITUDE):
            altitude_tool(game_data);
            break;
        case (RESET):
            reset_tool(game_data);
            break;
        case (PAINT):
            texture_tool(game_data);
        default:
            break;
    }
}

static void first_time(game_data_t *game_data)
{
    EDITOR current_tool = ALTITUDE;
    EDITOR tool_radius = 1;
    EDITOR map = set_map(EDITOR size);
    EDITOR texture = set_map(EDITOR size);
    EDITOR vector_map = get_map(EDITOR size);
    EDITOR font = sfFont_createFromFile
    ("assets/fonts/Raleway-Regular.ttf");
    EDITOR tooltip = sfText_create();
    sfText_setCharacterSize(EDITOR tooltip, 30);
    EDITOR alt_sens = 2;
    EDITOR move_sens = 1;
    sfText_setFont(EDITOR tooltip,
    EDITOR font);
}

void draw_editor(game_data_t *game_data)
{
    if (EDITOR map == NULL)
        first_time(game_data);
    if (sfKeyboard_isKeyPressed(sfKeyR))
        EDITOR current_tool = RESET;
    if (sfKeyboard_isKeyPressed(sfKeyT))
        EDITOR current_tool = ALTITUDE;
    if (sfKeyboard_isKeyPressed(sfKeyP))
        EDITOR current_tool = PAINT;
    check_hard_inputs(game_data);
    check_tools_input(game_data);
    draw_map(game_data);
    show_tooltips(game_data);
    sfRenderWindow_display(game_data->window_data->window);

}