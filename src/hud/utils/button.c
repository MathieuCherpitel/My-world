/*
** EPITECH PROJECT, 2020
** buttons
** File description:
** create buttons
*/

#include "include_structs.h"
#include "my_world.h"
#include "include_hud.h"

void check_sprite_button(button_t *button, sfVector2f mouse_position,
                                                    game_data_t *game_data)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(button->sprite_to_draw);
    if (sfFloatRect_contains
                (&bounds, mouse_position.x, mouse_position.y) == sfTrue) {
        button->sprite_to_draw = button->sprites[1];
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            button->sprite_to_draw = button->sprites[2];
            button->callback(game_data->window_data);
        }
    }
    else
        button->sprite_to_draw = button->sprites[0];
    if (button->selected == TRUE && button->tool_button == TRUE)
        button->sprite_to_draw = button->sprites[2];
}

void check_rectangle_button(button_t *button, sfVector2f mouse_position,
                                                    game_data_t *game_data)
{
    sfVector2f size = sfRectangleShape_getSize(button->rect);
    sfVector2f position = sfRectangleShape_getPosition(button->rect);

    if (mouse_position.x > position.x && mouse_position.x < position.x + size.x
                                && mouse_position.y > position.y
                                && mouse_position.y < position.y + size.y) {
        sfRectangleShape_setFillColor(button->rect, button->hover);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRectangleShape_setFillColor(button->rect, button->click);
            button->callback(game_data->window_data);
        }
    }
    else
        sfRectangleShape_setFillColor(button->rect, button->idle);
}

void is_button_clicked(button_t *button, sfVector2f mouse_position,
                                                        game_data_t *game_data)
{
    if (button->button_type == RECTANGLE)
        check_rectangle_button(button, mouse_position, game_data);
    if (button->button_type == SPRITE)
        check_sprite_button(button, mouse_position, game_data);
    if (button->button_type == SLIDER)
        check_slider_button(button, mouse_position, game_data);
}

int check_buttons(scenes_t *scene, game_data_t *game_data)
{
    int count = 0;
    sfVector2i position;
    sfVector2f mouse_position;

    while (scene->buttons[count] != NULL) {
        position = sfMouse_getPositionRenderWindow
                                            (game_data->window_data->window);
        mouse_position = (sfVector2f){.x = position.x, .y = position.y};
        is_button_clicked(scene->buttons[count], mouse_position, game_data);
        count++;
    }
    return (0);
}