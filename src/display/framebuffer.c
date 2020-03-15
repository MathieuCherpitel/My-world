/*
** EPITECH PROJECT, 2019
** framebuffer
** File description:
** create a framebuffer
*/

#include "my_world.h"
#include "include_structs.h"
#include <stdlib.h>

void clear_framebuffer(framebuffer_t *framebuffer)
{
    int unsigned i = 0;

    while (i < (framebuffer->height * framebuffer->width * 4)) {
        framebuffer->pixels[i] = 0;
        framebuffer->pixels[i + 1] = 0;
        framebuffer->pixels[i + 2] = 0;
        framebuffer->pixels[i + 3] = 255;
        i = i + 4;
    }
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *buffer;
    unsigned int i = 0;
    unsigned int surface = width * height * 4;

    buffer = malloc(sizeof(framebuffer_t));
    buffer->width = width;
    buffer->height = height;
    buffer->pixels = malloc(sizeof(sfUint8) * (surface));

    while (i < surface) {
        buffer->pixels[i] = 0;
        buffer->pixels[i + 1] = 0;
        buffer->pixels[i + 2] = 0;
        buffer->pixels[i + 3] = 255;
        i = i + 4;
    }
    return (buffer);
}
