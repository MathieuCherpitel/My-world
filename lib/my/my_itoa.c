/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** itoa returns an int from a string
*/

#include "libmy.h"
#include <stdlib.h>

int absolute_value(int nb)
{
    if (nb < 0)
        nb = nb * -1;
    return (nb);
}

char *my_nbr_array(int nb, char *buffer)
{
    if (nb < 0) {
        *buffer = '-';
        buffer++;
        nb = nb * -1;
    }
    if (nb > 9) {
        buffer = my_nbr_array(nb / 10, buffer);
    }
    nb = nb % 10;
    *buffer = nb + 48;
    buffer++;
    *buffer = 0;
    return (buffer);
}

char *my_itoa(int value)
{
    char *buffer;

    buffer = malloc(sizeof(char) * 11);
    my_nbr_array(value, buffer);
    return (buffer);
}
