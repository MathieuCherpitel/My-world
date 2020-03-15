/*
** EPITECH PROJECT, 2020
** main
** File description:
** main file
*/

#include "my_world.h"
#include "include_main_functions.h"

int main(int ac, __attribute__((unused)) char **av)
{
    if (ac == 1)
        return (my_world());
    else {
        my_putstr("invalid arg count, make sure to see the usage with -h\n");
        return (ERR);
    }
}