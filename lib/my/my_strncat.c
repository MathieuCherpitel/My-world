/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_strncat
*/

#include "libmy.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j;

    while (dest[i]) {
        i++;
    }
    j = i;
    i = 0;
    while (src[i] && i < nb) {
        dest[j + i] = src[i];
        i++;
    }
    dest[j + i] = '\0';
    return (dest);
}