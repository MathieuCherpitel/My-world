/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** handler sliders
*/

#include "include_structs.h"
#include "my_world.h"

int set_move_sens(game_data_t *game_data)
{
    int sens = 0;
    int print_sens;
    slider_t slider = game_data->scenes[EDITOR_SCENE]->buttons[6]->slider;
    sfVector2f position = sfSprite_getPosition(slider.slider_button);
    sfVector2f tmp = slider.left_position;

    while (tmp.x < position.x) {
        tmp.x += 45;
        sens += 1;
    }
    print_sens = sens - 2;
    sfText_setString(game_data->scenes[EDITOR_SCENE]->game_objects->text[3],
                                                        my_itoa(print_sens));
    return (sens);
}

int move_sens_slider_button(game_data_t *game_data)
{
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow
                                            (game_data->window_data->window);
    sfVector2f button_position = sfSprite_getPosition(game_data->scenes
                            [EDITOR_SCENE]->buttons[6]->slider.slider_button);
    sfVector2f new_position;
    slider_t slider = game_data->scenes[EDITOR_SCENE]->buttons[6]->slider;

    mouse_position = sfMouse_getPositionRenderWindow
                                        (game_data->window_data->window);
    new_position = (sfVector2f)
                        {.x = mouse_position.x - 15, .y = button_position.y};
    if (new_position.x < slider.left_position.x)
        new_position.x = slider.left_position.x;
    if (new_position.x > slider.right_position.x)
        new_position.x = slider.right_position.x;
    sfSprite_setPosition(slider.slider_button, new_position);
    game_data->editor_data->move_sens = set_move_sens(game_data);
    sfRenderWindow_display(game_data->window_data->window);
    return (EDITOR_SCENE);
}

int set_alt_sens(game_data_t *game_data)
{
    int sens = 0;
    int print_sens;
    slider_t slider = game_data->scenes[EDITOR_SCENE]->buttons[7]->slider;
    sfVector2f position = sfSprite_getPosition(slider.slider_button);
    sfVector2f tmp = slider.left_position;

    while (tmp.x < position.x) {
        tmp.x += 45;
        sens += 1;
    }
    print_sens = sens - 2;
    sfText_setString(game_data->scenes[EDITOR_SCENE]->game_objects->text[5],
                                                        my_itoa(print_sens));
    return (sens);
}

int alt_sens_slider_button(game_data_t *game_data)
{
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow
                                            (game_data->window_data->window);
    sfVector2f button_position = sfSprite_getPosition(game_data->scenes
                            [EDITOR_SCENE]->buttons[7]->slider.slider_button);
    sfVector2f new_position;
    slider_t slider = game_data->scenes[EDITOR_SCENE]->buttons[7]->slider;

    mouse_position = sfMouse_getPositionRenderWindow
                                        (game_data->window_data->window);
    new_position = (sfVector2f)
                        {.x = mouse_position.x - 15, .y = button_position.y};
    if (new_position.x < slider.left_position.x)
        new_position.x = slider.left_position.x;
    if (new_position.x > slider.right_position.x)
        new_position.x = slider.right_position.x;
    sfSprite_setPosition(slider.slider_button, new_position);
    game_data->editor_data->alt_sens = set_alt_sens(game_data);
    sfRenderWindow_display(game_data->window_data->window);
    return (EDITOR_SCENE);
}