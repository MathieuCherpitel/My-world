/*
** EPITECH PROJECT, 2020
** load sprites
** File description:
** loop to load sprites and set array of struct sprites_t
*/

#include "my_world.h"
#include "include_structs.h"
#include "include_load.h"
#include <stdlib.h>

int get_tab_len(char **tab)
{
    int count = 0;

    while (tab[count] != NULL)
        count++;
    return (count);
}

loaded_sprites_t *load_sprites(char *sprite_name,
                                            loaded_sprites_t *loaded_sprite)
{
    loaded_sprite = malloc(sizeof(loaded_sprites_t));
    loaded_sprite->sprites = malloc(sizeof(sfSprite *) * (2));

    if (loaded_sprite == NULL || loaded_sprite->sprites == NULL)
        return (NULL);
    my_putstr("loading: ");
    my_putstr(sprite_name);
    my_putchar('\n');
    loaded_sprite->sprites[0] = sfSprite_create();
    loaded_sprite->texture = sfTexture_createFromFile(sprite_name, NULL);
    sfSprite_setTexture(loaded_sprite->sprites[0],
                                            loaded_sprite->texture, sfTrue);
    loaded_sprite->sprites[1] = NULL;
    return (loaded_sprite);
}

window_data_t *load_loops(window_data_t *window_data, char **sprite_names,
                            __attribute__((unused)) char **sprites_sheet_names)
{
    int count = 0;
    int sprite_count = get_tab_len(sprite_names);

    while (count < sprite_count) {
        window_data->loaded_sprites[count] = load_sprites(sprite_names[count],
                                        window_data->loaded_sprites[count]);
        if (window_data->loaded_sprites[count] == NULL)
            return (NULL);
        count++;
    }
    window_data->loaded_sprites[count] = NULL;
    return (window_data);
}

window_data_t *load_textures(window_data_t *window_data)
{
    char *sprite_names[] = {"assets/images/sprites/menu_background.png",
    "assets/images/buttons/button_sprite_sheet.png",
    "assets/images/textures/1.jpg", "assets/images/textures/2.jpg",
    "assets/images/sprites/background_blue.jpg",
    "assets/images/sprites/background_white.jpg",
    "assets/images/sprites/slider_bar.png",
    "assets/images/sprites/slider_handler.png",
    "assets/images/sprites/preview_background_blue.jpg",
    "assets/images/sprites/preview_background_white.jpg", NULL};
    char *sprites_sheet_names[] = {NULL};
    int sprite_count = get_tab_len(sprite_names);
    int sprite_sheet_count = get_tab_len(sprites_sheet_names);

    window_data->loaded_sprites = malloc(sizeof(loaded_sprites_t *) *
                    (sprite_count + sprite_sheet_count + BUTTON_COUNT + 1));
    window_data = load_loops(window_data, sprite_names, sprites_sheet_names);
    window_data = load_buttons(window_data);
    if (window_data == NULL)
        return (NULL);
    return (window_data);
}
