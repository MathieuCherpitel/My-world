/*
** EPITECH PROJECT, 2020
** create scene
** File description:
** creae menu scene
*/

#include "my_world.h"
#include "include_structs.h"
#include "include_scenes.h"
#include <stdlib.h>

scenes_t *create_menu_scene(scenes_t *scene,
                            __attribute__((unused)) game_data_t *game_data)
{
    int button_count = 2;
    int sprite_count = 2;
    int text_count = 2;
    int animated_sprite_count = 2;

    my_putstr("creating menu scene...\n");
    scene->buttons = malloc(sizeof(button_t *) * (button_count + 1));
    scene->buttons = allocate_buttons(scene, button_count);
    scene->game_objects = malloc(sizeof(game_objects_t));
    scene->game_objects->sprites = malloc(sizeof(sfSprite *) *
                                                        (sprite_count + 1));
    scene->game_objects->animated_sprites = malloc(sizeof(animated_sprites_t *)
                                                * (animated_sprite_count + 1));
    scene->game_objects->text = malloc(sizeof(sfText * ) * text_count);
    scene->input_manager = NULL;
    return (scene);
}