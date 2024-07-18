/*
** EPITECH PROJECT, 2022
** table handling separator
** File description:
** separator_table
*/

#include "my.h"

char **result_table_loop(char **table, int count_dubble_pipe, char *buffer)
{
    int count_line = 0;
    int count_col = 0;
    table = malloc(sizeof(char *) * (count_dubble_pipe + 2));
    table[count_line] = malloc(sizeof(char) * (count_len(0, buffer)));
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '|' && buffer[i + 1] && buffer[i + 1] != '\0'
        && buffer[i + 1] == '|') {
            table[count_line][count_col] = '\0';
            i += 1;
            table[++count_line] = malloc(sizeof(char)
            * (count_len(i + 1, buffer)));
            count_col = 0;
        } else {
            table[count_line][count_col++] = buffer[i];
        }
    }
    table[count_line][count_col] = '\0';
    table[count_dubble_pipe + 1] = NULL;
    return table;
}

char **table_pipe(char *buffer)
{
    int count_dubble_pipe = 0;
    char **table;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '|' && buffer[i + 1] && buffer[i + 1]
        != '\0' && buffer[i + 1] == '|') {
            i++;
            count_dubble_pipe++;
        }
    }
    table = result_table_loop(table, count_dubble_pipe, buffer);
    return table;
}

char ***create_table_pipe(char *buffer)
{
    int count = 0;
    char ***sml;
    char **table_sml = table_pipe(buffer);
    int num = table_len(table_sml);

    sml = malloc(sizeof(char **) * (num + 8));
    for (int i = 0; i < num; i++) {
        if (count_value(table_sml[i], ' ') == my_strlen(table_sml[i])) {
            free(table_sml[i]);
            continue;
        }
        sml[count] = my_split(table_sml[i], " \t");
        free(table_sml[i]);
        count++;
    }
    free(table_sml);
    sml[count] = NULL;
    return sml;
}

char ***create_table_semicolon_and_and(char *buffer, char *c)
{
    int count = 0;
    char ***sml;
    char **table_sml = my_split(buffer, c);
    int num = table_len(table_sml);

    sml = malloc(sizeof(char **) * (num + 8));
    for (int i = 0; i < num; i++) {
        if (count_value(table_sml[i], ' ') == my_strlen(table_sml[i])) {
            free(table_sml[i]);
            continue;
        }
        sml[count] = my_split(table_sml[i], " \t");
        free(table_sml[i]);
        count++;
    }
    free(table_sml);
    sml[count] = NULL;
    return sml;
}
