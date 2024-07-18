/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** separator
*/

#include "my.h"

int count_len(int i, char *buffer)
{
    int count = 0;

    for (i; buffer[i] != '\0'; i++) {
        if (buffer[i] == '|' && buffer[i + 1]
        && buffer[i + 1] != '\0' && buffer[i + 1] == '|')
            break;
        count++;
    }
    return count + 1;
}

int check_semicolon(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != ';')
            return 1;
    }
    return 0;
}

void separator_dubble_pipe(char **sml_table, shell_a *info, char *buffer)
{
    char ***dubble_sml;
    char *table_merge = gather_table(sml_table, ' ', 1);
    int condi = 1;

    dubble_sml = create_table_pipe(table_merge);
    for (int i = 0; dubble_sml[i]; i++) {
        if (condi == 1) {
            pipe_check(dubble_sml[i], info, buffer);
            condi = info->status == 0 ? 0 : 1;
        } else {
            table_free(dubble_sml[i]);
        }
    }
    free(dubble_sml);
    free(table_merge);
    table_free(sml_table);
}

void separator_and(char **sml_table, shell_a *info, char *buffer)
{
    char ***dubble_sml;
    char *table_merge = gather_table(sml_table, ' ', 1);
    int condi = 1;

    dubble_sml = create_table_semicolon_and_and(table_merge, "&");
    for (int i = 0; dubble_sml[i]; i++) {
        if (condi == 1) {
            separator_dubble_pipe(dubble_sml[i], info, buffer);
            condi = info->status != 0 ? 0 : 1;
        } else {
            table_free(dubble_sml[i]);
        }
    }
    free(dubble_sml);
    free(table_merge);
    table_free(sml_table);
}

int separator_mix(shell_a *info, char *buffer)
{
    char ***sml;
    int res = 1;

    if (!check_semicolon(buffer) || !check_space(buffer))
        return 0;
    sml = create_table_semicolon_and_and(buffer, ";");
    for (int i = 0; sml[i] && res > 0; i++)
        res = check_and_pipe(sml[i]);
    for (int i = 0; sml[i] && res > 0; i++)
        separator_and(sml[i], info, buffer);
    if (res == -1) {
        write(2, "Invalid null command.\n", 23);
        info->status = 1;
    }
    if (res == 0 || res == -1)
        for (int i = 0; sml[i]; i++)
            table_free(sml[i]);
    free(sml);
    return 0;
}
