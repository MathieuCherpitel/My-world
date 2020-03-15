/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_strcat
*/

#include "libmy.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j;

    while (dest[i]) {
        i++;
    }
    j = i;
    i = 0;
    while (src[i]) {
        dest[j + i] = src[i];
        i++;
    }
    dest[j + i] = '\0';
    return (dest);
}
