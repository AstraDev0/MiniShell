/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** remove_quotation_mark
*/

#include "my.h"

char *remove_quotation_mark(char *buffer)
{
    int v = 0;
    int count = 0;
    char *new_buffer;

    for (int i = 0; buffer[i]; i++, buffer[i] != '\''
    && buffer[i] != '\"' ? v++ : v);
    new_buffer = malloc(sizeof(char) * (v + 1));
    for (int j = 0; buffer[j]; j++) {
        if (buffer[j] != '\'' && buffer[j] != '\"')
            new_buffer[count++] = buffer[j];
    }
    new_buffer[count] = 0;
    return new_buffer;
}
