/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_strcmp
*/

#include "libmy.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i]) {
        if (s1[i] == '\0')
            return (0);
        i++;
    }
    return (s1[i] - s2[i]);
}
