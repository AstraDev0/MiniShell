/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** utils_2
*/

#include "my.h"

void table_free(char **table)
{
    for (int i = 0; table[i]; i++)
        free(table[i]);
    free(table);
}

int count_value(char *buffer, char c)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == c)
            count++;
    return count;
}

int count_dubble_value(char *buffer, char c)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == c && buffer[i + 1] != '\0' && buffer[i + 1] == c)
            count++;
    return count;
}

int count_only_solo_c(char *buffer, char c)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == c && buffer[i + 1] != c
        && i != 0 && buffer[i - 1] != c)
            count++;
    return count;
}

void *utils_loop(int fd[], pid_t *pid)
{
    pipe(fd);
    if ((*pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }
}
