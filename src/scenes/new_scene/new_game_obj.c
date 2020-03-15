/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** create game objects for new scene
*/

#include "my_world.h"
#include "include_structs.h"
#include "include_scenes.h"
#include "include_hud.h"

static sfSprite **set_sprites(game_objects_t *game_objects,
                                                    game_data_t *game_data)
{
    game_objects->sprites[0] = game_data->window_data->loaded_sprites
                                                [MENU_BACKGROUND]->sprites[0];
    game_objects->sprites[1] = game_data->window_data->loaded_sprites
                                        [PREVIEW_BACKGROUND_BLUE]->sprites[0];
    game_objects->sprites[2] = game_data->window_data->loaded_sprites
                                        [PREVIEW_BACKGROUND_WHITE]->sprites[0];
    game_objects->sprites[3] = game_data->window_data->loaded_sprites
                                                    [TEXTURE_1]->sprites[0];
    sfSprite_scale(game_objects->sprites[3], (sfVector2f)
                                                    {.x = 0.247, .y = 0.247});
    game_objects->sprites[4] = game_data->window_data->loaded_sprites
                                                    [TEXTURE_2]->sprites[0];
    sfSprite_scale(game_objects->sprites[4], (sfVector2f)
                                                    {.x = 0.247, .y = 0.247});
    game_objects->sprites[5] = NULL;
    return (game_objects->sprites);
}

static sfText **set_text(game_objects_t *game_objects, game_data_t *game_data)
{
    sfColor gray = sfColor_fromRGB(170, 170, 170);

    game_objects->text[0] = init_text(game_data->window_data->fonts[RALEWAY],
                                                        "Map size", gray, 70);
    game_objects->text[1] = init_text(game_data->window_data->fonts[RALEWAY],
                                                    "Background", gray, 70);
    game_objects->text[2] = init_text(game_data->window_data->fonts[RALEWAY],
                                                        "Texture", gray, 70);
    game_objects->text[3] = init_text(game_data->window_data->fonts[RALEWAY],
                                                        "Return", gray, 50);
    game_objects->text[4] = init_text(game_data->window_data->fonts[RALEWAY],
                            my_itoa(game_data->editor_data->size), gray, 70);
    game_objects->text[5] = init_text(game_data->window_data->fonts[RALEWAY],
                                                        "Create", gray, 90);
    game_objects->text[6] = NULL;
    return (game_objects->text);
}
static sfText **edit_new_scene_text(game_objects_t *game_objects)
{
    game_objects->text[0] = edit_text(game_objects->text[0], 1300, 400);
    game_objects->text[1] = edit_text(game_objects->text[1], 750, 400);
    game_objects->text[2] = edit_text(game_objects->text[2], 300, 400);
    game_objects->text[3] = edit_text(game_objects->text[3], 10, 0);
    game_objects->text[4] = edit_text(game_objects->text[4], 1400, 490);
    game_objects->text[5] = edit_text(game_objects->text[5], 800, 200);
    return (game_objects->text);
}

game_objects_t *create_new_game_objects(game_objects_t *game_objects,
                                                        game_data_t *game_data)
{
    game_objects->sprites = set_sprites(game_objects, game_data);
    game_objects->text = set_text(game_objects, game_data);
    game_objects->text = edit_new_scene_text(game_objects);
    game_objects->animated_sprites[0] = NULL;
    return (game_objects);
}