/*
** EPITECH PROJECT, 2020
** draw scene
** File description:
** draw every game object of any scene
*/

#include "my_world.h"
#include "include_structs.h"
#include "include_event.h"
#include "include_editor.h"
#include "include_scenes.h"

void draw_text(game_objects_t *game_objects, window_data_t *window_data)
{
    int count = 0;

    while (game_objects->text[count] != NULL) {
        sfRenderWindow_drawText(window_data->window, game_objects->text
                                                            [count], NULL);
        count++;
    }
}

void draw_buttons(button_t **buttons, window_data_t *window_data)
{
    int count = 0;
    sfRenderWindow *w = window_data->window;

    while (buttons[count] != NULL) {
        if (buttons[count]->button_type == RECTANGLE)
            sfRenderWindow_drawRectangleShape(w, buttons[count]->rect, NULL);
        else if (buttons[count]->button_type == SPRITE) {
            sfRenderWindow_drawSprite(w, buttons[count]->sprite_to_draw, NULL);
            if (buttons[count]->tool_button == TRUE
                                        && buttons[count]->selected == TRUE)
                sfRenderWindow_drawSprite(w, buttons[count]->sprites[2], NULL);
        }
        else {
            sfRenderWindow_drawSprite(w, buttons
                                            [count]->slider.slider_bar, NULL);
            sfRenderWindow_drawSprite(w, buttons
                                        [count]->slider.slider_button, NULL);
        }
        count++;
    }
}

void draw_game_objects(game_objects_t *game_objects, window_data_t *window_data)
{
    int count = 0;

    sfRenderWindow_clear(window_data->window, sfBlack);
    while (game_objects->sprites[count] != NULL) {
        sfRenderWindow_drawSprite(window_data->window, game_objects->sprites
                                                                [count], NULL);
        count++;
    }
}

void change_background_size(editor_data_t *editor_data)
{
    sfSprite_setScale(editor_data->background, (sfVector2f){.x = 1, .y = 1});
    sfSprite_setPosition(editor_data->background,
                                                (sfVector2f){.x = 0, .y = 0});
}

void draw_scene(game_data_t *game_data, int scene_index)
{
    check_event(game_data->window_data);
    if (scene_index == EDITOR_SCENE) {
        change_background_size(game_data->editor_data);
        game_data->current_scene = EDITOR_SCENE;
        return (draw_editor(game_data));
    }
    sfRenderWindow_clear(game_data->window_data->window, sfBlack);
    draw_game_objects(game_data->scenes[scene_index]->game_objects,
                                                        game_data->window_data);
    draw_buttons(game_data->scenes[scene_index]->buttons,
                                                        game_data->window_data);
    draw_text(game_data->scenes[scene_index]->game_objects,
                                                        game_data->window_data);
    draw_special(game_data, scene_index);
}