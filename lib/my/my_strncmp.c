/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_strcmp
*/

#include "libmy.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (i < n) {
        if (s1[i] == '\0')
            return (0);
        i++;
    }
    return (s1[i] - s2[i]);
}
