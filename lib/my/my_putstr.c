/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_putstr
*/

#include "libmy.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}
