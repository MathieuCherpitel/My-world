/*
** EPITECH PROJECT, 2020
** create scenes
** File description:
** init scenes
*/

#include "my_world.h"
#include "include_structs.h"
#include "include_scenes.h"
#include <stdlib.h>

scenes_t **allocate_scenes(game_data_t *game_data)
{
    int count = 0;

    game_data->scenes = malloc(sizeof(scenes_t *) * SCENE_NUMBER);
    while (count < SCENE_NUMBER) {
        game_data->scenes[count] = malloc(sizeof(scenes_t));
        if (game_data->scenes[count] == NULL)
            return (NULL);
        count++;
    }
    return (game_data->scenes);
}

game_data_t *create_scenes(game_data_t *game_data)
{
    my_putstr("\ncreating scenes\n");
    game_data->scenes = allocate_scenes(game_data);
    game_data->scenes[LOADING_SCENE] = create_loading_scene(game_data->scenes
                                                [LOADING_SCENE], game_data);
    game_data->scenes[LOAD_MAP_SCENE] = create_load_map_scene
                                (game_data->scenes[LOAD_MAP_SCENE], game_data);
    game_data->scenes[NEW_SCENE] = create_new_scene
                                    (game_data->scenes[NEW_SCENE], game_data);
    game_data->scenes[EDITOR_SCENE] = create_editor_scene
                                (game_data->scenes[EDITOR_SCENE], game_data);
    if (game_data->scenes[LOADING_SCENE] == NULL
        || game_data->scenes[LOAD_MAP_SCENE] == NULL
        || game_data->scenes[NEW_SCENE] == NULL
        || game_data->scenes[EDITOR_SCENE] == NULL
    )
        return (NULL);
    return (game_data);
}

button_t **allocate_buttons(scenes_t *scene, int button_count)
{
    int count = 0;

    while (count < button_count) {
        scene->buttons[count] = malloc(sizeof(button_t));
        if (scene->buttons[count] == NULL)
            return (NULL);
        count++;
    }
    scene->buttons[count] = NULL;
    return (scene->buttons);
}