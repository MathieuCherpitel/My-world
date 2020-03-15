/*
** EPITECH PROJECT, 2019
** compute line
** File description:
** draw line functions
*/

#include "my_world.h"
#include "include_structs.h"
#include "include_display.h"
#include <stdlib.h>

void draw_straight(framebuffer_t *framebuffer, sfVector2i point_a,
sfVector2i point_b, sfColor color)
{
    int x = point_a.x;
    int y = point_a.y;

    while (y != point_b.y) {
        y++;
        my_put_pixel(framebuffer, (int)x, (int)y, color);
    }
}

void draw_steep(framebuffer_t *framebuffer, sfVector2i point_a,
sfVector2i point_b, sfColor color)
{
    equation_t *equation = compute_equation(point_a, point_b);
    int y = point_a.y;
    int x = 0;

    while (y != point_b.y) {
        x = -((equation->b - (float)y)/equation->a);
        y++;
        my_put_pixel(framebuffer, (int)x, (int)y, color);
    }
    free(equation);
}

void draw_normal(framebuffer_t *framebuffer, sfVector2i point_a,
sfVector2i point_b, sfColor color)
{
    equation_t *equation = compute_equation(point_a, point_b);
    int x = point_a.x;
    int y = 0;

    while (x != point_b.x) {
        y = equation->a*(float)x + equation->b;
        x++;
        my_put_pixel(framebuffer, (int)x, (int)y, color);
    }
    free(equation);
}

equation_t * compute_equation(sfVector2i point_a, sfVector2i point_b)
{
    equation_t *equation = malloc(sizeof(equation_t));
    float a_minus_b = (float)point_b.y - (float)point_a.y;
    float b_minus_a = (float)point_b.x - (float)point_a.x;
    equation->a = a_minus_b / b_minus_a;
    equation->b = (float)point_a.y - equation->a * (float)point_a.x;
    return (equation);
}
