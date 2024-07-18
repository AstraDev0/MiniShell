/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** gather_table
*/

#include "my.h"

char *gather_table(char **table, char c, int separator)
{
    int count = 0;
    char *buffer;

    for (int y = 0; table[y]; y++) {
        if (y != 0 && separator)
            count++;
        for (int x = 0; table[y][x]; x++, count++);
    }
    buffer = malloc(sizeof(char) * (count + 1));
    count = 0;
    for (int y = 0; table[y]; y++) {
        if (y != 0 && separator)
            buffer[count++] = c;
        for (int x = 0; table[y][x]; x++)
            buffer[count++] = table[y][x];
    }
    buffer[count] = '\0';
    return buffer;
}
