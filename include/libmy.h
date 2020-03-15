/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** libmy
*/

//lib functions
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strdup(char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strstr(char *str, char const *to_find);
char *my_strncpy(char *dest, char const *src, int n);
int my_put_nbr(int nb);
//my_str functions
char *my_strstr(char *str, char const *to_find);
int  check_occurence(char *str, char const *to_find, int i);
//my_get_nbr functions
int check_to_high(int nb, int sign);
int check_sign(char const *str);
int my_getnbr(char const *);
//my_itoa functions
int absolute_value(int nb);
char *my_nbr_array(int nb, char *buffer);
char *my_itoa(int value);
//malloc arr functions
char **malloc_arr(char *str, char *seps);
int count_words(char *str, char *seps);
int check_sep(char *str, char *seps, int loop);
//my_str to word array functions
char **my_str_to_word_array(char *str, char *seps);
char *word_to_arr(char *arr, char *str, char *seps, int *total_count);
int is_operator(char *str, char c);