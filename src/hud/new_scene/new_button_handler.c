/*
** EPITECH PROJECT, 2020
** load scene button handler
** File description:
** handle buttons from load scene
*/

#include "my_world.h"
#include "include_structs.h"

int set_size(game_data_t *game_data)
{
    int size = 12;
    slider_t slider = game_data->scenes[NEW_SCENE]->buttons[7]->slider;
    sfVector2f position = sfSprite_getPosition(slider.slider_button);
    sfVector2f tmp = slider.left_position;

    while (tmp.x < position.x) {
        tmp.x += 45;
        size += 4;
    }
    sfText_setString(game_data->scenes[NEW_SCENE]->game_objects->text[4],
                                                            my_itoa(size));
    return (size);
}

int size_slider_button(game_data_t *game_data)
{
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow
                                            (game_data->window_data->window);
    sfVector2f button_position = sfSprite_getPosition(game_data->scenes
                                [NEW_SCENE]->buttons[7]->slider.slider_button);
    sfVector2f new_position;
    slider_t slider = game_data->scenes[NEW_SCENE]->buttons[7]->slider;

    mouse_position = sfMouse_getPositionRenderWindow
                                        (game_data->window_data->window);
    new_position = (sfVector2f)
                        {.x = mouse_position.x - 15, .y = button_position.y};
    if (new_position.x < slider.left_position.x)
        new_position.x = slider.left_position.x;
    if (new_position.x > slider.right_position.x)
        new_position.x = slider.right_position.x;
    sfSprite_setPosition(slider.slider_button, new_position);
    sfRenderWindow_display(game_data->window_data->window);
    game_data->editor_data->size = set_size(game_data);
    return (NEW_SCENE);
}

int create_button(game_data_t *game_data)
{
    game_data->current_scene = EDITOR_SCENE;
    game_data->editor_data->map = NULL;
    return (EDITOR_SCENE);
}

int return_button(game_data_t *game_data)
{
    game_data->current_scene = LOAD_MAP_SCENE;
    return (LOAD_MAP_SCENE);
}