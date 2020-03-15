/*
** EPITECH PROJECT, 2020
** create load scene
** File description:
** load_scene
*/

#include "my_world.h"
#include "include_structs.h"
#include "include_hud.h"
#include "include_scenes.h"
#include <stdlib.h>

static scenes_t *allocate_scene(scenes_t *scene)
{
    int button_count = 8;
    int sprite_count = 5;
    int text_count = 6;
    int animated_sprite_count = 0;
    int texture_count = 0;

    scene->buttons = malloc(sizeof(button_t *) * (button_count + 1));
    scene->buttons = allocate_buttons(scene, button_count);
    scene->game_objects = malloc(sizeof(game_objects_t));
    scene->game_objects->sprites = malloc(sizeof(sfSprite *) *
                                                (sprite_count + 1));
    scene->game_objects->animated_sprites = malloc(sizeof(animated_sprites_t *)
                                                * (animated_sprite_count + 1));
    scene->game_objects->text = malloc(sizeof(sfText *) * (text_count + 1));
    scene->game_objects->textures = malloc(sizeof(sfTexture **) *
                                                        (texture_count + 1));
    scene->input_manager = new_input_manager;
    return (scene);
}

scenes_t *change_preview_place(scenes_t *scene)
{
    sfSprite_setPosition(scene->game_objects->sprites[1],
                                            (sfVector2f){.x = 960, .y = 520});
    sfSprite_setPosition(scene->game_objects->sprites[2],
                                            (sfVector2f){.x = 840, .y = 520});
    sfSprite_setPosition(scene->game_objects->sprites[3],
                                            (sfVector2f){.x = 310, .y = 520});
    sfSprite_setPosition(scene->game_objects->sprites[4],
                                            (sfVector2f){.x = 430, .y = 520});
    return (scene);
}

void new_input_manager(__attribute__((unused)) scenes_t *scene,
                        __attribute__((unused)) window_data_t *window_data)
{
    return;
}

scenes_t *create_new_scene(scenes_t *scene, game_data_t *game_data)
{
    my_putstr("creating load scene...\n");
    scene = allocate_scene(scene);
    game_data->editor_data->size = 16;
    if (scene == NULL)
        return (NULL);
    scene->game_objects = create_new_game_objects
                                            (scene->game_objects, game_data);
    scene->buttons = create_new_buttons(scene, game_data);
    scene->buttons = set_new_buttons_handler(scene);
    scene = change_preview_place(scene);
    return (scene);
}