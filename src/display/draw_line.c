/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** draw line functions
*/

#include "my_world.h"
#include "include_structs.h"
#include "include_display.h"
#include <stdlib.h>

void check_exchange_straight(framebuffer_t *framebuffer,
sfVector2i  point_a , sfVector2i  point_b, sfColor color)
{
    if (point_a.y > point_b.y)
        draw_straight(framebuffer, point_b, point_a, sfRed);
    else
        draw_straight(framebuffer, point_a, point_b, color);
}

void check_exchange_steep(framebuffer_t *framebuffer,
sfVector2i  point_a, sfVector2i  point_b, sfColor color)
{
    if (point_a.y > point_b.y)
        draw_steep(framebuffer, point_b, point_a, color);
    else
        draw_steep(framebuffer, point_a, point_b, color);
}

void check_exchange_normal(framebuffer_t *framebuffer,
sfVector2i  point_a , sfVector2i  point_b, sfColor color)
{
    if (point_a.x > point_b.x)
        draw_normal(framebuffer, point_b, point_a, color);
    else
        draw_normal(framebuffer, point_a, point_b, color);
}

int draw_line(framebuffer_t *framebuffer , sfVector2i  point_a ,
sfVector2i  point_b, sfColor color)
{
    equation_t *equation = malloc(sizeof(equation_t));

    equation = compute_equation(point_a, point_b);
    if (point_a.x == point_b.x)
        check_exchange_straight(framebuffer, point_a, point_b, color);
    else if (equation->a > 1 || equation->a < -1)
        check_exchange_steep(framebuffer, point_a, point_b, color);
    else
        check_exchange_normal(framebuffer, point_a, point_b, color);
    free(equation);
    return (0);
}