/*
** EPITECH PROJECT, 2020
** load map buttons
** File description:
** creates and sets butons for load map scene
*/

#include "my_world.h"
#include "include_structs.h"
#include "include_hud.h"
#include <stdlib.h>

button_t **set_load_map_buttons_handler(scenes_t *scene)
{
    scene->buttons[0]->callback = button_load;
    scene->buttons[1]->callback = button_new;
    scene->buttons[2]->callback = button_quit;
    return (scene->buttons);
}

button_t **create_load_map_buttons(scenes_t *scene)
{
    sfColor blue_transparent = sfColor_fromRGBA(140, 160, 160, 150);
    scene->buttons[0] = malloc(sizeof(button_t));
    scene->buttons[1] = malloc(sizeof(button_t));
    scene->buttons[2] = malloc(sizeof(button_t));
    scene->buttons[3] = NULL;
    if (scene->buttons[0] == NULL || scene->buttons[1] == NULL)
        return (NULL);
    init_rectangle_button(scene->buttons[0], (sfVector2f){.x = 805, .y = 320},
                                            (sfVector2f){.x = 240, .y = 90});
    init_rectangle_button(scene->buttons[1], (sfVector2f){.x = 805, .y = 460},
                                            (sfVector2f){.x = 240, .y = 90});
    init_rectangle_button(scene->buttons[2], (sfVector2f){.x = 805, .y = 600},
                                            (sfVector2f){.x = 240, .y = 90});
    edit_rectangle_button(scene->buttons[0], sfTransparent, blue_transparent,
                                                                sfTransparent);
    edit_rectangle_button(scene->buttons[1], sfTransparent, blue_transparent,
                                                                sfTransparent);
    edit_rectangle_button(scene->buttons[2], sfTransparent, blue_transparent,
                                                                sfTransparent);
    return (scene->buttons);
}