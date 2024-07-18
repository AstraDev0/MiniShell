/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** utils_3
*/

#include "my.h"

int count_loop_values(char *c, int i, char letter)
{
    if (c[i] == letter)
        return 1;
    if (c[i] != '\0')
        count_loop_values(c, i + 1, letter);
    return 0;
}

int count_values(char *buffer, char *c)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (count_loop_values(c, 0, buffer[i]))
            count++;
    return count;
}
