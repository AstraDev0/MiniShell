/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** getline
*/

#include "my.h"

size_t get_line(shell_a *info, size_t characters)
{
    char *buffer = NULL;
    size_t bufsize = 0;

    characters = getline(&buffer, &bufsize, stdin);
    condition_getline(buffer, info);
    free(buffer);
    return characters;
}

void condition_getline(char *buffer, shell_a *info)
{
    char *new_buff;
    int u = 0;

    if (my_strlen(buffer) > 1 && buffer[0] != '\0') {
        new_buff = malloc(sizeof(char) * my_strlen(buffer));
        for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++, u++)
            new_buff[i] = buffer[i];
        new_buff[u] = '\0';
        start_minishell_main(info, new_buff);
        free(new_buff);
    }
}
