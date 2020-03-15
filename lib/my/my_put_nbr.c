/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_putnbr
*/

#include "libmy.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        if (nb == -2147483648) {
            my_put_nbr(2147);
            my_put_nbr(483648);
            return (0);
        }
        nb = nb * -1;
    }
    if (nb >= 10)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + 48);
    return (0);
}
