/*
** EPITECH PROJECT, 2020
** state machine
** File description:
** determines the scene to be active
*/

#include "my_world.h"
#include "include_structs.h"

int check_loading_state(void)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
        return (LOAD_MAP_SCENE);
    return (LOADING_SCENE);
}

int check_load_map_state(void)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
        return (LOADING_SCENE);
    return (LOAD_MAP_SCENE);
}

int state_machine(int scene_index)
{
    switch (scene_index)
    {
    case LOADING_SCENE:
        scene_index = check_loading_state();
        break;
    case LOAD_MAP_SCENE:
        scene_index = check_load_map_state();
        break;
    default:
        break;
    }
    return (scene_index);
}