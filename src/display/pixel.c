/*
** EPITECH PROJECT, 2019
** pixel
** File description:
** display a pixel function
*/

#include "my_world.h"
#include "include_structs.h"

void my_put_pixel(framebuffer_t *framebuffer, int x, int y, sfColor color)
{
    if (x >= (int)(framebuffer->width)  || x < 0)
        return;
    if (y >= (int)(framebuffer->height) || y < 0)
        return;
    framebuffer->pixels[((x + 1) + framebuffer->width * y) * 4] = color.r;
    framebuffer->pixels[((x + 1) + framebuffer->width * y) * 4 + 1] = color.g;
    framebuffer->pixels[((x + 1) + framebuffer->width * y) * 4 + 2] = color.b;
}