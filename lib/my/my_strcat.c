/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** my_strcat.c
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char *src)
{
    int j = 0;
    int i = 0;

    while (dest[i])
        i += 1;
    while (src[j]) {
        dest[i] = src[j];
        i = i + 1;
        j = j + 1;
    }
    dest[i] = '\0';
    return dest;
}
