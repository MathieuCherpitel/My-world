/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** creates and sets buttons for new scene
*/

#include "my_world.h"
#include "include_structs.h"
#include "include_hud.h"

button_t **set_new_buttons_handler(scenes_t *scene)
{
    scene->buttons[0]->callback = button_new_return;
    scene->buttons[1]->callback = button_new_create;
    scene->buttons[2]->callback = button_texture_1;
    scene->buttons[3]->callback = button_texture_2;
    scene->buttons[4]->callback = button_background_blue;
    scene->buttons[5]->callback = button_background_white;
    scene->buttons[6]->callback = button_new_create;
    scene->buttons[7]->callback = button_slider_size;
    return (scene->buttons);
}

void create_butons_1(scenes_t *scene)
{
    sfColor blue_transparent = sfColor_fromRGBA(140, 160, 160, 150);

    init_rectangle_button(scene->buttons[0], (sfVector2f){.x = 0, .y = 0},
                                            (sfVector2f){.x = 180, .y = 70});
    edit_rectangle_button(scene->buttons[0], sfTransparent, blue_transparent,
                                                                sfTransparent);
    init_rectangle_button(scene->buttons[1], (sfVector2f){.x = 780, .y = 210},
                                            (sfVector2f){.x = 326, .y = 100});
    edit_rectangle_button(scene->buttons[1], sfTransparent, sfTransparent,
                                                                sfTransparent);
    init_rectangle_button(scene->buttons[2], (sfVector2f){.x = 310, .y = 520},
                                            (sfVector2f){.x = 100, .y = 50});
    edit_rectangle_button(scene->buttons[2], sfTransparent, blue_transparent,
                                                            blue_transparent);
    init_rectangle_button(scene->buttons[3], (sfVector2f){.x = 430, .y = 520},
                                            (sfVector2f){.x = 100, .y = 50});
    edit_rectangle_button(scene->buttons[3], sfTransparent, blue_transparent,
                                                            blue_transparent);
}

void create_butons_2(scenes_t *scene, game_data_t *game_data)
{
    sfColor blue_transparent = sfColor_fromRGBA(140, 160, 160, 150);

    init_rectangle_button(scene->buttons[4], (sfVector2f){.x = 960, .y = 520},
                                                (sfVector2f){.x = 97, .y = 54});
    edit_rectangle_button(scene->buttons[4], sfTransparent, blue_transparent,
                                                            blue_transparent);
    init_rectangle_button(scene->buttons[5], (sfVector2f){.x = 840, .y = 520},
                                                (sfVector2f){.x = 97, .y = 54});
    edit_rectangle_button(scene->buttons[5], sfTransparent, blue_transparent,
                                                            blue_transparent);
    init_sprite_button(scene->buttons[6], (sfVector2f){.x = 900, .y = 750},
    (sfVector2f){.x = 0.5, .y = 0.5}, game_data->window_data->loaded_sprites
                                                [VALIDATE_BUTTON]->sprites);
    init_slider_button(scene->buttons[7], (sfVector2f){.x = 1330, .y = 600},
                                                                    game_data);
}

button_t **create_new_buttons(scenes_t *scene, game_data_t *game_data)
{
    if (scene->buttons == NULL)
        return (NULL);
    create_butons_1(scene);
    create_butons_2(scene, game_data);
    return (scene->buttons);
}