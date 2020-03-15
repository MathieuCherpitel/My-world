/*
** EPITECH PROJECT, 2020
** include file
** File description:
** include for folder load
*/

#ifndef _LOAD_H
#define _LOAD_H

// include struct
#include "include_structs.h"

// function includes from load assets
window_data_t *load(window_data_t *window_data);
window_data_t *load_fonts(window_data_t *window_data);
window_data_t *load_music(window_data_t *window_data);

// function include from load button
window_data_t * load_buttons(window_data_t *window_data);
loaded_sprites_t *set_sprite_array(loaded_sprites_t *loaded_sprites,
                                        sfTexture *texture, sfIntRect rect);
sfSprite **set_sprites_from_rect(sfSprite **sprite_array, sfTexture *texture,
                                                            sfIntRect rect);

// function include from load sprites
window_data_t *load_textures(window_data_t *window_data);
window_data_t *load_loops(window_data_t *window_data, char **sprite_names,
                                                char **sprites_sheet_names);
loaded_sprites_t *load_sprites(char *sprite_name,
                                            loaded_sprites_t *loaded_sprite);
int get_tab_len(char **tab);

#endif /* !_LOAD_H */
