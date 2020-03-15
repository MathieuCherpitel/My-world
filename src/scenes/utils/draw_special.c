/*
** EPITECH PROJECT, 2020
** draw special
** File description:
** special draw functions for some scenes
*/

#include "my_world.h"
#include "include_structs.h"
#include "include_scenes.h"

void draw_specific_scene_animation(game_data_t *game_data, int scene_index)
{
    switch (scene_index)
    {
    case LOADING_SCENE:
        sfRenderWindow_setMouseCursorVisible(game_data->window_data->window,
                                                                    sfFalse);
        text_animation(game_data->scenes[scene_index]);
        break;
    default:
        sfRenderWindow_setMouseCursorVisible(game_data->window_data->window,
                                                                    sfTrue);
        break;
    }
}

void draw_selected_background(game_data_t *game_data)
{
    if (game_data->editor_data->background_selected_index == BACKGROUND_BLUE) {
        sfRectangleShape_setOutlineThickness(game_data->scenes
                            [game_data->current_scene]->buttons[4]->rect, 2);
        sfRectangleShape_setOutlineThickness(game_data->scenes
                            [game_data->current_scene]->buttons[5]->rect, 0);
        sfRenderWindow_drawRectangleShape(game_data->window_data->window,
        game_data->scenes[game_data->current_scene]->buttons[2]->rect, NULL);
    }
    if (game_data->editor_data->background_selected_index
                                                        == BACKGROUND_WHITE) {
        sfRectangleShape_setOutlineThickness(game_data->scenes
                            [game_data->current_scene]->buttons[5]->rect, 2);
        sfRectangleShape_setOutlineThickness(game_data->scenes
                            [game_data->current_scene]->buttons[4]->rect, 0);
        sfRenderWindow_drawRectangleShape(game_data->window_data->window,
        game_data->scenes[game_data->current_scene]->buttons[3]->rect, NULL);
    }
}

void draw_selected_texture(game_data_t *game_data)
{
    if (game_data->editor_data->texture_selected_index == TEXTURE_1) {
        sfRectangleShape_setOutlineThickness(game_data->scenes
                            [game_data->current_scene]->buttons[2]->rect, 2);
        sfRectangleShape_setOutlineThickness(game_data->scenes
                            [game_data->current_scene]->buttons[3]->rect, 0);
        sfRenderWindow_drawRectangleShape(game_data->window_data->window,
        game_data->scenes[game_data->current_scene]->buttons[2]->rect, NULL);
    }
    if (game_data->editor_data->texture_selected_index == TEXTURE_2) {
        sfRectangleShape_setOutlineThickness(game_data->scenes
                            [game_data->current_scene]->buttons[3]->rect, 2);
        sfRectangleShape_setOutlineThickness(game_data->scenes
                            [game_data->current_scene]->buttons[2]->rect, 0);
        sfRenderWindow_drawRectangleShape(game_data->window_data->window,
        game_data->scenes[game_data->current_scene]->buttons[3]->rect, NULL);
    }
}

void draw_special(game_data_t *game_data, int scene_index)
{
    if (game_data->current_scene == NEW_SCENE) {
        draw_selected_texture(game_data);
        draw_selected_background(game_data);
    }
    draw_specific_scene_animation(game_data, scene_index);
}