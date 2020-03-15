/*
** EPITECH PROJECT, 2020
** load
** File description:
** load all assets
*/

#include "my_world.h"
#include "include_structs.h"
#include "include_load.h"
#include <stdlib.h>

window_data_t *load_music(window_data_t *window_data)
{
    char *music_assets[] = {"assets/music/loading.wav", NULL};
    int count = 0;
    int load_count = 0;

    window_data->musics = malloc(sizeof(sfMusic *) * (count + 1));
    if (window_data->musics == NULL)
        return (NULL);
    while (music_assets[count] != NULL)
        count++;
    if (count > 0) {
        while (load_count < count) {
            my_putstr("loading: ");
            my_putstr(music_assets[load_count]);
            my_putchar('\n');
            window_data->musics[load_count] = sfMusic_createFromFile
                                            (music_assets[load_count]);
            load_count++;
        }
    }
    return (window_data);
}

window_data_t *load_fonts(window_data_t *window_data)
{
    char *font_assets[] = {"assets/fonts/Raleway-Regular.ttf", NULL};
    int count = 0;
    int load_count = 0;

    window_data->fonts = malloc(sizeof(sfFont *) * (count + 1));
    if (window_data->fonts == NULL)
        return (NULL);
    while (font_assets[count] != NULL)
        count++;
    if (count > 0) {
        while (load_count < count) {
            my_putstr("loading: ");
            my_putstr(font_assets[load_count]);
            my_putchar('\n');
            window_data->fonts[load_count] = sfFont_createFromFile
                                            (font_assets[load_count]);
            load_count++;
        }
    }
    return (window_data);
}

window_data_t *load(window_data_t *window_data)
{
    my_putstr("loading images\n");
    window_data = load_textures(window_data);
    if (window_data == NULL)
        return (NULL);
    my_putstr("\nloading music\n");
    window_data = load_music(window_data);
    if (window_data == NULL)
        return (NULL);
    my_putstr("\nloading fonts\n");
    window_data = load_fonts(window_data);
    if (window_data == NULL)
        return (NULL);
    my_putstr("loading done\n");
    return (window_data);
}