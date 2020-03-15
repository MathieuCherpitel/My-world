/*
** EPITECH PROJECT, 2020
** create scene
** File description:
** creates sditor scene
*/

#include "my_world.h"
#include "include_structs.h"
#include "include_hud.h"
#include "include_editor.h"
#include "include_hud.h"
#include "include_scenes.h"
#include <stdlib.h>

static scenes_t *allocate_scene(scenes_t *scene)
{
    int button_count = 8;
    int sprite_count = 0;
    int text_count = 6;
    int animated_sprite_count = 0;
    int texture_count = 2;

    scene->buttons = malloc(sizeof(button_t *) * (button_count + 1));
    scene->buttons = allocate_buttons(scene, button_count);
    scene->game_objects = malloc(sizeof(game_objects_t));
    scene->game_objects->sprites = malloc(sizeof(sfSprite *) *
                                                    (sprite_count + 1));
    scene->game_objects->animated_sprites = malloc(sizeof(animated_sprites_t *)
                                                * (animated_sprite_count + 1));
    scene->game_objects->text = malloc(sizeof(sfText * ) * (text_count + 1));
    scene->game_objects->textures = malloc(sizeof(sfTexture *) *
                                                        (texture_count + 1));
    scene->input_manager = editor_input_manager;
    scene->buttons[8] = NULL;
    return (scene);
}

scenes_t *create_editor_scene(scenes_t *scene, game_data_t *game_data)
{
    my_putstr("creating editor scene...\n");
    scene = allocate_scene(scene);
    if (scene == NULL)
        return (NULL);
    scene->game_objects = create_editor_game_objects(scene->game_objects,
                                                                    game_data);
    scene->buttons = create_editor_buttons(scene, game_data);
    scene->buttons = set_editor_buttons_handler(scene);
    scene->buttons[4]->selected = TRUE;
    return (scene);
}