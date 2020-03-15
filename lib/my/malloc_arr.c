/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** malloc arr
*/

#include "libmy.h"
#include <stdlib.h>

int checksep(char *str, char *seps, int loop)
{
    int count = 0;
    int seploop = my_strlen(seps) - 1;

    while (seploop >= 0) {
        if (str[loop] == seps[seploop])  {
            count = 1;
        }
        seploop--;
    }
    return (count);
}

int count_words(char *str, char *seps)
{
    int count = 1;
    int loop = 0;

    while (loop <= my_strlen(str)) {
    count = count + checksep(str, seps, loop);
    loop++;
    }
    return (count);
}

char **malloc_arr(char *str, char *seps)
{
    int loop = 0;
    int word_count = count_words(str, seps);
    char **allocated_arr = malloc(sizeof(char *) * (word_count + 1));

    while (loop < word_count) {
        allocated_arr[loop] = malloc(sizeof(char) * (my_strlen(str) + 1));
        loop++;
    }
    return (allocated_arr);
}
