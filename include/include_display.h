/*
** EPITECH PROJECT, 2020
** include file
** File description:
** functions includes from display folder
*/

#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "include_structs.h"

// functions includes from compute line
void draw_straight(framebuffer_t *framebuffer, sfVector2i point_a, sfVector2i point_b, sfColor color);
void draw_steep(framebuffer_t *framebuffer, sfVector2i point_a, sfVector2i point_b, sfColor color);
void draw_normal(framebuffer_t *framebuffer, sfVector2i point_a, sfVector2i point_b, sfColor color);
equation_t * compute_equation(sfVector2i point_a, sfVector2i point_b);

// functions includes from draw line
int draw_line(framebuffer_t *framebuffer, sfVector2i  point_a, sfVector2i  point_b, sfColor color);
void check_exchange_normal(framebuffer_t *framebuffer, sfVector2i  point_a, sfVector2i  point_b, sfColor color);
void check_exchange_steep(framebuffer_t *framebuffer, sfVector2i  point_a, sfVector2i  point_b, sfColor color);
void check_exchange_straight(framebuffer_t *framebuffer, sfVector2i  point_a, sfVector2i  point_b, sfColor color);

// functions includes from framebuffer
void clear_framebuffer(framebuffer_t *framebuffer);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);

// function include from pixel
void my_put_pixel(framebuffer_t *framebuffer, int x, int y, sfColor color);




#endif /* !_DISPLAY_H */