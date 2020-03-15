/*
** EPITECH PROJECT, 2020
** include file
** File description:
** my world main include file
*/

#ifndef _MY_WORLD_H
#define _MY_WORLD_H

#include "libmy.h"

// unused 
#define UNUSED __attribute__((unused))
// macros
// boolean
#define TRUE 0
#define FALSE 1

// return values
#define ERR 84
#define SUCCESS 0

// window size and scene count
#define HEIGHT 1080
#define WIDTH 1920
#define SCENE_NUMBER 4

// editor shortcut macro
#define EDITOR game_data->editor_data->

// buttons macros
#define RECTANGLE 1
#define SPRITE 2
#define SLIDER 3

// texture name macros
// sprites

// DISCLAIMER 
// when adding an asset, add it to just before the buttons and cgange the start value of the button sprite array creation in 
// load buttons load_buttons while count < BUTTON_COUNT + assets_count_before_buttons and change the count to the 
#define BUTTON_COUNT 35
enum sprites {
    MENU_BACKGROUND,        // 1 sprite
    BUTTON,                 // 1 sprite
    TEXTURE_1,              // 1 sprite (multi-rect)
    TEXTURE_2,              // 1 sprite (multi-rect)
    BACKGROUND_WHITE,       // 1 sprite
    BACKGROUND_BLUE,        // 1 sprite
    SLIDER_BAR,             // 1 sprite
    SLIDER_HANDLER,         // 1 sprite
    PREVIEW_BACKGROUND_WHITE,//1 sprite
    PREVIEW_BACKGROUND_BLUE,// 1 sprite
    //buttons
    RIGHT_BUTTON,           // 3 sprites
    LEFT_BUTTON,            // 3 sprites
    UP_BUTTON,              // 3 sprites
    DOWN_BUTTON,            // 3 sprites
    MENU_BUTTON,            // 3 sprites
    VOL_BUTTON,             // 3 sprites
    PAUSE_BUTTON,           // 3 sprites
    RIGHT_ARROW_BUTTON,     // 3 sprites
    LEFT_ARROW_BUTTON,      // 3 sprites
    UP_ARROW_BUTTON,        // 3 sprites
    DOWN_ARROW_BUTTON,      // 3 sprites
    CONTROLLER_BUTTON,      // 3 sprites
    RAISE_BUTTON,           // 3 sprites
    DEMOTE_BUTTON,          // 3 sprites
    HELP_BUTTON,            // 3 sprites
    EXIT_BUTTON,            // 3 sprites
    SAVE_BUTTON,            // 3 sprites
    DELETE_BUTTON,          // 3 sprites
    SHOP_BUTTON,            // 3 sprites
    GRID_BUTTON,            // 3 sprites
    PLUS_BUTTON,            // 3 sprites
    MINUS_BUTTON,           // 3 sprites
    ROTATE_BUTTON,          // 3 sprites
    SETTINGS_BUTTON,        // 3 sprites
    CANCEL_BUTTON,          // 3 sprites
    VALIDATE_BUTTON,        // 3 sprites
    ROTATE2_BUTTON,         // 3 sprites
    HORIZONTAL_SCALE_BUTTON,// 3 sprites
    VERTICAL_SCALE_BUTTON,  // 3 sprites
};

// button id enum
enum button_id {
    NONE,                   // nothing to do
    NEW,                    // changes to "new scene"
    LOAD,                   // changes to "load scene"
    QUIT,                   // quits the editor
    RETURN,                 // returns to previous scene
    CREATE,                 // changes to "editor scene"
    SET_TEXTURE_1,          // changes the texture set to TEXTURE_1
    SET_TEXTURE_2,          // changes the texture set to TEXTURE_2
    SET_BACKGROUND_WHITE,   // sets the background to BACKGROUND_WHITE
    SET_BACKGROUND_BLUE,    // sets the background to BACKGROUND_BLUE
    SIZE,                   // changes the size of the map (slider button)
    EXIT_EDITOR,            // returns to the load map scene
    SAVE_EDITOR,            // saves the current satet of the map in save1.map
    RADIUS_EDITOR,          // changes the radius of effect of the tools
    DEMOTE_EDITOR,          // set the altitude of the point(s) to 0
    SCALE_EDITOR,           // change altitude of points
    PAINT_EDITOR,           // paint a texture from the texture set selected
    MOVE_SENS,              // changes the sensibility of the movement
    alt_sens           // changes the sensibility of the altitude modifications
};

enum tools_id {
    ALTITUDE,
    RESET,
    PAINT,
};

// fonts
#define RALEWAY 0

// musics
#define LOADING_MUSIC 0

// scenes index
enum scenes {
    LOADING_SCENE,
    LOAD_MAP_SCENE,
    NEW_SCENE,
    EDITOR_SCENE,
};

#endif /* !_MY_WORLD_H */