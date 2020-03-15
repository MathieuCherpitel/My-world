/*
** EPITECH PROJECT, 2020
** editor buttons
** File description:
** creates ans sets buttons for editor scene
*/

#include "my_world.h"
#include "include_structs.h"
#include "include_hud.h"

button_t **set_editor_buttons_handler(scenes_t *scene)
{
    scene->buttons[0]->callback = button_editor_return;
    scene->buttons[1]->callback = button_editor_save;
    scene->buttons[2]->callback = button_editor_radius;
    scene->buttons[3]->callback = button_editor_demote;
    scene->buttons[4]->callback = button_editor_scale;
    scene->buttons[5]->callback = button_editor_paint;
    scene->buttons[6]->callback = button_editor_move_sens;
    scene->buttons[7]->callback = button_editor_alt_sens;
    return (scene->buttons);
}

button_t **create_slider_buttons(scenes_t *scene, game_data_t *game_data)
{
    init_slider_button(scene->buttons[2], (sfVector2f){.x = 1610, .y = 80},
                                                                game_data);
    init_slider_button(scene->buttons[6], (sfVector2f){.x = 1610, .y = 240},
                                                                game_data);
    init_slider_button(scene->buttons[7], (sfVector2f){.x = 1610, .y = 400},
                                                                game_data);
    return (scene->buttons);
}

button_t **create_sprite_buttons(scenes_t *scene, game_data_t *game_data)
{
    init_sprite_button(scene->buttons[0], (sfVector2f){.x = 0, .y = 5},
    (sfVector2f){.x = 0.5, .y = 0.5}, game_data->window_data->loaded_sprites
                                                    [CANCEL_BUTTON]->sprites);
    init_sprite_button(scene->buttons[1], (sfVector2f){.x = 100, .y = 0},
    (sfVector2f){.x = 0.5, .y = 0.5}, game_data->window_data->loaded_sprites
                                                    [SAVE_BUTTON]->sprites);
    init_sprite_button(scene->buttons[3], (sfVector2f){.x = 500, .y = 0},
    (sfVector2f){.x = 0.5, .y = 0.5}, game_data->window_data->loaded_sprites
                                                    [DEMOTE_BUTTON]->sprites);
    init_sprite_button(scene->buttons[4], (sfVector2f){.x = 400, .y = 5},
    (sfVector2f){.x = 0.5, .y = 0.5}, game_data->window_data->loaded_sprites
                                            [VERTICAL_SCALE_BUTTON]->sprites);
    init_sprite_button(scene->buttons[5], (sfVector2f){.x = 600, .y = 5},
    (sfVector2f){.x = 0.5, .y = 0.5}, game_data->window_data->loaded_sprites
                                            [GRID_BUTTON]->sprites);
    return (scene->buttons);
}

button_t **create_editor_buttons(scenes_t *scene, game_data_t *game_data)
{
    scene->buttons = create_slider_buttons(scene, game_data);
    scene->buttons = create_sprite_buttons(scene, game_data);
    scene->buttons[3]->tool_button = TRUE;
    scene->buttons[4]->tool_button = TRUE;
    scene->buttons[5]->tool_button = TRUE;
    return (scene->buttons);
}
