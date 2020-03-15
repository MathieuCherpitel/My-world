/*
** EPITECH PROJECT, 2020
** include file
** File description:
** include structs
*/

#ifndef _STRUCT_H
#define _STRUCT_H

// csfml includes
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Audio.h>

//struct for compute line, it has the a and b of the equation y = ax + b
typedef struct equation_s {
    float a;
    float b;
}equation_t;

// struct for sprite animations
typedef struct animated_sprites_s {
    sfSprite **sprites;                                                 // array of the sprites that composes the animation
    int sprite_count;                                                   // number of sprites in the animation (in the array)
}animated_sprites_t;

// struct of every sprites loaded at the begining of the program
typedef struct loaded_sprites_s {
    sfSprite **sprites;                                                 // array of sprites (for multpile sprites for one texture)
    sfTexture *texture;
}loaded_sprites_t;

// framebuffer struct
typedef struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
}framebuffer_t;

//init window structs, these structs have all the data about the window
typedef struct window_data {
    sfVideoMode video_mode;
    sfRenderWindow *window;
    sfEvent event;
    framebuffer_t *framebuffer;
    loaded_sprites_t **loaded_sprites;                                  // array of array of sprites (for unique or multiple sprites per texture)
    sfFont **fonts;                                                     // aray of fonts
    sfMusic **musics;                                                   // array of musics
    sfView *view;
    int button_click_id;
}window_data_t;

// struct for slider button
typedef struct slider_s {
    sfSprite *slider_bar;
    sfSprite *slider_button;
    sfVector2f left_position;                                           // left position is the extreme left position of the slider
    sfVector2f right_position;                                          // right position is the extreme right poition of the slider
}slider_t;

// struct for buttons
typedef struct button_s {
    sfRectangleShape *rect;                                             // hitbox of the button
    void(*callback)(window_data_t *);                                   // adress of the function called by the button
    sfColor idle;                                                       // status color
    sfColor hover;
    sfColor click;
    sfSprite **sprites;                                                 // sprite 0 is idle, 1 is hover and 3 is click
    int button_type;                                                    // either RECTANGLE or SPRITE to know if it is a sprite or rectangle type button
    sfSprite *sprite_to_draw;                                           // the sprite displayed by draw button in draw scene
    slider_t slider;
    int tool_button;                                                    // TRUE or FALSE if the button is or not a tool
    int selected;                                                       // only used for tools display the clicked sprite if tool selected
}button_t;

// game objects struct
typedef struct game_objects_s {
    sfSprite **sprites;                                                 // array of unique sprites
    sfTexture **textures;                                               // array of textures
    animated_sprites_t **animated_sprites;                              // array of animated sprites (array of array of sprites)
    sfText **text;                                                      // array of texts to be drawn
    sfMusic *music;
}game_objects_t;

// struct for scenes
typedef struct scenes_s {
    button_t **buttons;
    game_objects_t *game_objects;
    void(*input_manager)(struct scenes_s *, window_data_t *);           // function pointer to the input manager, cannot handle scene change (handled by the state machine)
}scenes_t;

// editor data struct
typedef struct editor_data_s {
    int size;                                                           // multiple of 4    
    int **map;                                                          // values : z axis
    int **texture;
    int set;
    sfSprite *background;
    sfTexture *texture_set;
    sfVector2f **vector_map;
    int texture_selected_index;                                         // 1 or 2 for TEXTURE_1 and TEXTURE_2
    int background_selected_index; 
    int current_tool;
    int tool_radius;
    int zoom;                                 // 4 or 5 for BACKGROUND_WHITE and BACKGROUND_BLUE
    sfText *tooltip;
    sfFont *font;
    int move_sens;
    int alt_sens;
}editor_data_t;

// main game data struct
typedef struct game_data_s {
    window_data_t *window_data;                                         // window data
    scenes_t **scenes;                                                  // array of scenes
    int current_scene;                                                  // index of the current scene
    editor_data_t *editor_data;
}game_data_t;

// function pointer for button handle
typedef int (*func_ptr_t)(game_data_t *);

#endif /* !_STRUCT_H */