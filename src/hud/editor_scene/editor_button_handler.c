/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** handler for editor buttons
*/

#include "my_world.h"
#include "include_structs.h"
#include "include_scenes.h"

int exit_editor_button(game_data_t *game_data)
{
    game_data->current_scene = LOAD_MAP_SCENE;
    return (LOAD_MAP_SCENE);
}

int save_editor_button(__attribute__((unused))  game_data_t *game_data)
{
    return (EDITOR_SCENE);
}

int set_radius(game_data_t *game_data)
{
    int radius = 0;
    slider_t slider = game_data->scenes[EDITOR_SCENE]->buttons[2]->slider;
    sfVector2f position = sfSprite_getPosition(slider.slider_button);
    sfVector2f tmp = slider.left_position;

    while (tmp.x < position.x) {
        tmp.x += 90;
        radius += 1;
    }
    if (radius == 0)
        radius = 1;
    sfText_setString(game_data->scenes[EDITOR_SCENE]->game_objects->text[1],
                                                            my_itoa(radius));
    return (radius);
}

int radius_slider_button(game_data_t *game_data)
{
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow
                                            (game_data->window_data->window);
    sfVector2f button_position = sfSprite_getPosition(game_data->scenes
                            [EDITOR_SCENE]->buttons[2]->slider.slider_button);
    sfVector2f new_position;
    slider_t slider = game_data->scenes[EDITOR_SCENE]->buttons[2]->slider;

    mouse_position = sfMouse_getPositionRenderWindow
                                        (game_data->window_data->window);
    new_position = (sfVector2f)
                        {.x = mouse_position.x - 15, .y = button_position.y};
    if (new_position.x < slider.left_position.x)
        new_position.x = slider.left_position.x;
    if (new_position.x > slider.right_position.x)
        new_position.x = slider.right_position.x;
    sfSprite_setPosition(slider.slider_button, new_position);
    game_data->editor_data->tool_radius = set_radius(game_data);
    sfRenderWindow_display(game_data->window_data->window);
    return (EDITOR_SCENE);
}