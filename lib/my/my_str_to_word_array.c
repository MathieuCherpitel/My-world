/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** str to word array
*/

#include "libmy.h"
#include <stddef.h>

int is_operator(char *str, char c)
{
    int cnt_str = 0;

    while (str[cnt_str] != '\0') {
        if (str[cnt_str] == c)
            return (1);
        cnt_str++;
    }
    return (0);
}

char *word_to_arr(char *arr, char *str, char *seps, int *total_count)
{
    int loop = 0;

    while (*total_count < my_strlen(str)
    && is_operator(seps, str[*total_count]) == 0) {
        arr[loop] = str[*total_count];
        total_count[0]++;
        loop++;
    }
    arr[loop] = '\0';
    return (arr);
}

char **my_str_to_word_array(char *str, char *seps)
{
    int loop = 0;
    int total_count = 0;
    char **arr = malloc_arr(str, seps);

    while (total_count < my_strlen(str)) {
        if (is_operator(seps, str[total_count]) == 0) {
            arr[loop] = word_to_arr(arr[loop], str, seps, &total_count);
            loop++;
        }
        total_count++;
    }
    arr[loop] = NULL;
    return (arr);
}
