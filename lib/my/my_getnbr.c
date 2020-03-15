/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_getnbr.c
*/

#include "libmy.h"

int check_to_high(int nb, int sign)
{
    if (sign < 0 && nb < 0)
            return (84);
    else if (sign > 0 && nb < 0)
            return (84);
    else
        return (0);
}

int check_sign(char const *str)
{
    int i = 0;
    int minus = 0;
    int sign = 1;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            minus++;
        i++;
    }
    if (minus %2 != 0)
        sign = -sign;
    return (sign);
}

int my_getnbr(char const *str)
{
    int sign = 1;
    int i = 0;
    int nb = 0;

    if (str[0] == '+' || str[0] == '-') {
        sign = check_sign(str);
        while (str[i] == '+' || str[i] == '-')
            i++;
    }
    while (str[i] != '\0') {
        if (str[i] < 48 || str[i] > 57)
            return (nb * sign);
        nb = nb * 10 + (str[i] - 48);
        i++;
        if (check_to_high(nb, sign) == 84)
            return (0);
    }
    nb = nb * sign;
    return (nb);
}
