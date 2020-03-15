/*
** EPITECH PROJECT, 2020
** create scene
** File description:
** creates loading map
*/

#include "my_world.h"
#include "include_structs.h"
#include "include_hud.h"
#include "include_scenes.h"
#include <math.h>
#include <stdlib.h>

static scenes_t *allocate_scene(scenes_t *scene)
{
    int button_count = 0;
    int sprite_count = 1;
    int text_count = 2;
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
    scene->input_manager = loading_input_manager;
    scene->buttons[0] = NULL;
    return (scene);
}

static game_objects_t *create_game_objects(game_objects_t *game_objects,
                                                    game_data_t *game_data)
{
    sfColor gray = sfColor_fromRGB(170, 170, 170);

    game_objects->sprites[0] = game_data->window_data->loaded_sprites
                                                [MENU_BACKGROUND]->sprites[0];
    game_objects->sprites[1] = NULL;
    game_objects->text[0] = init_text(game_data->window_data->fonts[RALEWAY],
                                                        "My world", gray, 100);
    game_objects->text[1] = init_text(game_data->window_data->fonts[RALEWAY],
                                            "Press space to begin", gray, 40);
    game_objects->text[0] = edit_text(game_objects->text[0] , 720, 370);
    game_objects->text[1] = edit_text(game_objects->text[1] , 750, 500);
    game_objects->text[2] = NULL;
    game_objects->animated_sprites[0] = NULL;
    game_objects->music = game_data->window_data->musics[LOADING_SCENE];
    sfMusic_setLoop(game_objects->music, sfTrue);
    sfMusic_play(game_objects->music);
    return (game_objects);
}

void text_animation(scenes_t *scene)
{
    sfColor gray = sfColor_fromRGBA(170, 170, 170, 255);
    static int gradiant = 150;
    static int sign = -1;

    gradiant += 1 * sign;
    if (gradiant <= 150)
        sign = 1;
    if (gradiant >= 200)
        sign = -1;
    gray.r = gradiant;
    gray.g = gradiant;
    gray.b = gradiant;
    sfText_setColor(scene->game_objects->text[1], gray);
}

void loading_input_manager(__attribute__((unused)) scenes_t *scene,
                    __attribute__((unused)) window_data_t *window_data)
{
    return;
}

scenes_t *create_loading_scene(scenes_t *scene, game_data_t *game_data)
{
    my_putstr("creating loading scene...\n");
    scene = allocate_scene(scene);
    if (scene == NULL)
        return (NULL);
    scene->game_objects = create_game_objects(scene->game_objects, game_data);
    return (scene);
}