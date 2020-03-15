/*
** EPITECH PROJECT, 2020
** create load map scene
** File description:
** creates a scene
*/

#include "my_world.h"
#include "include_structs.h"
#include "include_scenes.h"
#include "include_hud.h"
#include <stdlib.h>

static scenes_t *allocate_scene(scenes_t *scene)
{
    int button_count = 3;
    int sprite_count = 2;
    int text_count = 3;
    int animated_sprite_count = 0;
    int texture_count = 0;

    scene->buttons = malloc(sizeof(button_t *) * (button_count + 1));
    scene->buttons = allocate_buttons(scene, button_count),
    scene->game_objects = malloc(sizeof(game_objects_t));
    scene->game_objects->sprites = malloc(sizeof(sfSprite *) *
                                                (sprite_count + 1));
    scene->game_objects->animated_sprites = malloc(sizeof(animated_sprites_t *)
                                                * (animated_sprite_count + 1));
    scene->game_objects->text = malloc(sizeof(sfText * ) * (text_count + 1));
    scene->game_objects->textures = malloc(sizeof(sfTexture **) *
                                                        (texture_count + 1));
    scene->input_manager = loading_map_input_manager;
    return (scene);
}

static game_objects_t *create_game_objects(game_objects_t *game_objects,
                                                        game_data_t *game_data)
{
    sfColor gray = sfColor_fromRGB(170, 170, 170);

    game_objects->sprites[0] = game_data->window_data->loaded_sprites
                                                [MENU_BACKGROUND]->sprites[0];
    game_objects->sprites[1] = NULL;
    game_objects->text[0] = init_text(game_data->window_data->fonts
                                                [RALEWAY], "Load", gray, 100);
    game_objects->text[1] = init_text(game_data->window_data->fonts
                                                [RALEWAY], "New", gray, 100);
    game_objects->text[2] = init_text(game_data->window_data->fonts
                                                [RALEWAY], "Quit", gray, 100);
    game_objects->text[0] = edit_text(game_objects->text[0] , 805, 300);
    game_objects->text[1] = edit_text(game_objects->text[1] , 815, 440);
    game_objects->text[2] = edit_text(game_objects->text[2] , 825, 580);
    game_objects->text[3] = NULL;
    game_objects->animated_sprites[0] = NULL;
    game_objects->music = game_data->window_data->musics[LOADING_SCENE];
    return (game_objects);
}

void loading_map_input_manager(__attribute__((unused)) scenes_t *scene,
                            __attribute__((unused)) window_data_t *window_data)
{
    return;
}

scenes_t *create_load_map_scene(scenes_t *scene, game_data_t *game_data)
{
    my_putstr("creating load map scene...\n");
    scene = allocate_scene(scene);
    if (scene == NULL)
        return (NULL);
    scene->game_objects = create_game_objects(scene->game_objects, game_data);
    scene->buttons = create_load_map_buttons(scene);
    scene->buttons = set_load_map_buttons_handler(scene);
    if (scene->game_objects == NULL || scene->buttons == NULL)
        return (NULL);
    return (scene);
}