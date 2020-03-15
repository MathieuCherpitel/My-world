/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_strdup
*/

#include "libmy.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int i = 0;
    int lg = 0;
    char *str;

    while (src[lg])
        lg++;
    str = malloc(sizeof(char) * (lg + 1));
    while (i < lg) {
        str[i] = src[i];
        i++;
    }
    return (str);
}
