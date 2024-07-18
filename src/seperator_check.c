/*
** EPITECH PROJECT, 2022
** separator checking
** File description:
** seperator_check
*/

#include "my.h"

int check_pipe_next(char *table_merge, int pass)
{
    for (int i = 0; table_merge[i]; i++) {
        if (table_merge[i] == '|'
        && ((table_merge[i - 1] && (table_merge[i - 1] == '|'
        || (table_merge[i - 1] == ' ' && table_merge[i - 2]
        && table_merge[i - 2] == '|'))
        && table_merge[i + 1] && (table_merge[i + 1] == '|'
        || (table_merge[i + 1] == ' ' && table_merge[i + 2]
        && table_merge[i + 2] == '|')))))
            pass = -1;
    }
    return pass;
}

int check_pipe(char **table_buffer)
{
    char *table_merge = gather_table(table_buffer, ' ', 1);
    int pass = 1;
    int other_letter = 1;

    for (int i = 0; table_merge[i]; i++)
        if (table_merge[i] != '|' && table_merge[i] != ' ')
            other_letter = 0;
    if (other_letter) {
        free(table_merge);
        return -1;
    }
    pass = check_pipe_next(table_merge, pass);
    free(table_merge);
    return pass;
}

int check_and_next(int pass, char *table_merge)
{
    int other_letter = 0;

    for (int i = 0; table_merge[i]; i++) {
        if (table_merge[i] != '&' && table_merge[i] != ' ')
            other_letter = 1;
        if (other_letter == 1 && table_merge[i] == '&'
        && ((table_merge[i - 1] && (table_merge[i - 1] == '&'
        || (table_merge[i - 1] == ' ' && table_merge[i - 2]
        && table_merge[i - 2] == '&'))
        && table_merge[i + 1] && (table_merge[i + 1] == '&'
        || (table_merge[i + 1] == ' ' && table_merge[i + 2]
        && table_merge[i + 2] == '&')))))
            pass = -1;
    }
    return pass;
}

int check_and(char **table_buffer)
{
    char *table_merge = gather_table(table_buffer, ' ', 1);
    int pass = 1;
    int other_letter = 1;

    for (int i = 0; table_merge[i]; i++)
        if (table_merge[i] != '&' && table_merge[i] != ' ')
            other_letter = 0;
    if (other_letter) {
        free(table_merge);
        return 0;
    }
    pass = check_and_next(pass, table_merge);
    free(table_merge);
    return pass;
}

int check_and_pipe(char **table_buffer)
{
    int res = 1;

    res = check_and(table_buffer);
    if (res > 0)
        res = check_pipe(table_buffer);
    return res;
}
