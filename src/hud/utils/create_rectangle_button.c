/*
** EPITECH PROJECT, 2020
** create button
** File description:
** create button with a rectangle shape
*/

#include "my_world.h"
#include "include_structs.h"

void edit_rectangle_button(button_t *button, sfColor idle, sfColor hover,
                                                            sfColor click)
{
    button->idle = idle;
    button->hover = hover;
    button->click = click;
}

void init_rectangle_button(button_t *button, sfVector2f position,
                                                            sfVector2f size)
{
    button->rect = sfRectangleShape_create();
    button->button_type = RECTANGLE;
    sfRectangleShape_setFillColor(button->rect, sfTransparent);
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    button->tool_button = FALSE;
    button->selected = FALSE;
}