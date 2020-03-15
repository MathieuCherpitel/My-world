/*
** EPITECH PROJECT, 2020
** my world
** File description:
** main file
*/

#include "my_world.h"
#include "include_structs.h"
#include "include_display.h"
#include "include_load.h"
#include "include_scenes.h"
#include "include_main_functions.h"
#include <stdlib.h>

int destroy(window_data_t *window_data)
{
    sfRenderWindow_destroy(window_data->window);
    free(window_data);
    return (0);
}

window_data_t *init_render_window(window_data_t *window_data)
{
    window_data->video_mode.width = WIDTH;
    window_data->video_mode.height = HEIGHT;
    window_data->video_mode.bitsPerPixel = 32;
    window_data->window = sfRenderWindow_create(window_data->video_mode,
    "my world", sfResize | sfClose, NULL);
    window_data->framebuffer = framebuffer_create(WIDTH, HEIGHT);
    sfRenderWindow_setFramerateLimit(window_data->window, 60);
    clear_framebuffer(window_data->framebuffer);
    return (window_data);
}

int my_world(void)
{
    window_data_t *window_data = malloc(sizeof(window_data_t));
    game_data_t *game_data = malloc(sizeof(game_data_t));
    int return_value = 0;

    game_data->editor_data = malloc(sizeof(editor_data_t));
    if (window_data == NULL || game_data == NULL || game_data->editor_data == NULL)
        return (ERR);
    game_data->window_data = init_render_window(window_data);
    game_data->window_data = load(window_data);
    if (game_data->window_data == NULL)
        return (ERR);
    game_data = create_scenes(game_data);
    my_putstr("scenes created\n\n");
    if (game_data->scenes == NULL)
        return (ERR);
    return_value = game_loop(game_data);
    destroy(window_data);
    return(return_value);
}