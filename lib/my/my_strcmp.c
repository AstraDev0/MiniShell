/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** my_strcmp.c
*/

#include "../../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while ((s1[i] != '\0') && (s1[i] == s2[i]) && (s2[i] != '\0'))
        i++;
    return (s1[i] - s2[i]);
}
