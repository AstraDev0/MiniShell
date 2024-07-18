/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** check_glue_redirection
*/

#include "my.h"

int redirection_glue_no_space(char *buffer)
{
    for (int i = 0; buffer[i]; i++) {
        if ((buffer[i] == '<' && buffer[i + 1] == '>')
        || (buffer[i] == '>' && buffer[i + 1] == '<'))
            return 84;
    }
    return 0;
}

int redirection_glue(char *buffer, char c)
{
    char **split = my_split(buffer, " \t");

    for (int i = 0; split[i]; i++) {
        if (redirection_glue_no_space(split[i]))
            return 1;
        if (split[i + 1] && ((split[i][my_strlen(split[i]) - 1] == '>'
        && split[i + 1][0] == '<') || (split[i][my_strlen(split[i]) - 1] == '<'
        && split[i + 1][0] == '>')))
            return 1;
    }
    table_free(split);
    return 0;
}
