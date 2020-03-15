/*
** EPITECH PROJECT, 2020
** create text
** File description:
** generic function to display text
*/

#include "my_world.h"
#include "include_structs.h"

// edits a sfText by modifying it's position

sfText *edit_text(sfText *text, int x, int y)
{
    sfVector2f pos = {.x = x, .y = y};

    sfText_setPosition(text, pos);
    return (text);
}

// initialise a sfText ofject by setting it's font, string and color

sfText *init_text(sfFont *font, char *string, sfColor color, int size)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setString(text, string);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, color);
    return (text);
}