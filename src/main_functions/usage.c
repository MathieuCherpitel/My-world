/*
** EPITECH PROJECT, 2020
** usage
** File description:
** usage display file
*/

#include "my_world.h"

void usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_world [file name] map save\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfile name : .map file containing the ");
    my_putstr("positions of the points on the map\n");
    my_putstr("\tIf you want to import a map make sure to ");
    my_putstr("move it to the map folder.\n");
}