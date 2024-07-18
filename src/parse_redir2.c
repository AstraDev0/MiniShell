/*
** EPITECH PROJECT, 2022
** there were too many fucntions in the parse_redirection.c file by itself
** File description:
** parse_redir2
*/

#include "my.h"

int get_redirection(char *buff, int nbr)
{
    int count = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if ((buff[i] == '<' || buff[i] == '>')
        && ((i == 0 || (buff[i - 1]
        && buff[i - 1] != '>' && buff[i - 1] != '<')
        || (buff[i + 1] == '\0' || (buff[i + 1]
        && buff[i + 1] != '\0' && buff[i + 1] != '>' && buff[i + 1] != '<')))))
            count++;
        if (count == nbr)
            return i;
    }
    return 0;
}

int count_rdr_split(char *buff)
{
    int count = 3;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == ' ')
            count += 1;
    }
    return count;
}
