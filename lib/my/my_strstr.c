/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_strstr
*/

#include "libmy.h"
#include <stddef.h>

int  check_occurence(char *str, char const *to_find, int i)
{
    int j = 0;

    while (to_find[j] != '\0') {
        if (to_find[j] != str[i])
            return (1);
        j++;
        i++;
    }
    return (0);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (check_occurence(str, to_find, i) == 0)
            return (&str[i]);
        i++;
    }
    return (NULL);
}
