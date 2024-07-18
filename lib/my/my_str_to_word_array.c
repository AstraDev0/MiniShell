/*
** EPITECH PROJECT, 2021
** my_str_word_array.c
** File description:
** my_str_word_array.c
*/

#include "../../include/my.h"

int my_check(char str)
{
    int r = 0;
    int i = 0;
    char al[] = " ";

    while (al[i] != '\0') {
        if (al[i] != str)
            r = 1;
        i++;
    }
    return (r);
}

char *my_strncat_custom(char *dest, char const *src, int nb, int nb2)
{
    int i = 0;
    int c = 0;
    int p = 0;

    while (i < nb)
        i++;
    while (src[i] != '\0' && i < nb2) {
        dest[c] = src[i];
        c++;
        i++;
    }
    dest[c] = '\0';
    return (dest);
}

char **result2(int i, char const *str, int c, int o)
{
    char **result;
    int d = 0;
    int p;

    result = malloc(sizeof(char *) * (i));
    while (c <= i) {
        p = my_check(str[c]);
        if (c - d != 0 && p == 0) {
            result[o] = malloc(sizeof(char) * (c - d + 1));
            result[o] = my_strncat_custom(result[o], str, d, c);
            result[o + 1] = '\0';
        }
        if (p == 0) {
            o++;
            d = c + 1;
        }
        c++;
    }
    return (result);
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int c = 0;
    int o = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (result2(i, str, c, o));
}
