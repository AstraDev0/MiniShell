/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** my_revstr.c
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int i = 0;
    char v[my_strlen(str) + 1];
    int a = my_strlen(str);
    int t = 0;

    for (i; i >= 0; i--) {
        v[t] = str[i];
        t++;
    }
    for (int y = 0; y <= a; y++) {
        str[y] = v[y + 1];
    }
    str[a] = '\0';
    return (str);
}
