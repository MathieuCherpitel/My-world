/*
** EPITECH PROJECT, 2020
** check envent
** File description:
** checks if an event is triggered
*/

#include "my_world.h"
#include "include_structs.h"
#include <SFML/Window.h>

int check_close(window_data_t *window_data)
{
    if (window_data->event.type == sfEvtClosed) {
        sfRenderWindow_close(window_data->window);
        return (SUCCESS);
    }
    return (SUCCESS);
}

int check_event(window_data_t *window_data)
{
    int return_value = 0;

    while (sfRenderWindow_pollEvent(window_data->window, &window_data->event))
        return_value = check_close(window_data);
    return (return_value);
}