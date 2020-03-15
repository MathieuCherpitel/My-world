/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_strlen
*/

#include "libmy.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}
