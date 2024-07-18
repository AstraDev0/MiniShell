/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** parse_redirection
*/

#include "my.h"

char **other_buffer(char *buff, int *u, char **new_order)
{
    int len = get_redirection(buff, 2);
    int lenght_buff = my_strlen(buff);
    int j = 0;
    char *buffer_other = malloc(sizeof(char) * (lenght_buff - len + 1));
    char **table_split;

    for (int i = len; i < lenght_buff; i++, j++)
        buffer_other[j] = buff[i];
    buffer_other[j] = '\0';
    table_split = my_split(buffer_other, "\t ");
    for (int i = 0; table_split[i]; i++) {
        new_order[*u] = malloc(sizeof(char) * (my_strlen(table_split[i]) + 1));
        my_strcpy(new_order[*u], table_split[i]);
        *u = *u + 1;
        free(table_split[i]);
    }
    free(table_split);
    free(buffer_other);
}

void order_add_separator(char **new_order, char *buff, char **split_sp, int *u)
{
    new_order[*u] = malloc(sizeof(char) * 2);
    new_order[*u][0] = buff[get_redirection(buff, 1)];
    new_order[*u][1] = '\0';
    *u = *u + 1;
    new_order[*u] = malloc(sizeof(char) * (my_strlen(split_sp[0]) + 1));
    my_strcpy(new_order[*u], split_sp[0]);
    *u = *u + 1;
}

char **parse_table(char **order)
{
    char *buff = gather_table(order, ' ', 1);
    char **split_parse = my_split(buff, "><");
    char **split_space = my_split(split_parse[0], " \t");
    char **new_order = malloc(sizeof(char *) * (count_rdr_split(buff)));
    int u = 0;

    for (int i = 1; split_space[i]; i++, u++) {
        new_order[u] = malloc(sizeof(char) * (my_strlen(split_space[i]) + 1));
        my_strcpy(new_order[u], split_space[i]);
    }
    order_add_separator(new_order, buff, split_space, &u);
    get_redirection(buff, 2) != 0 ? other_buffer(buff, &u, new_order) : 0;
    new_order[u] = NULL;
    free(buff);
    table_free(split_space);
    table_free(split_parse);
    return new_order;
}

void parse_redirection(char **order, shell_a *info)
{
    char *buffer;
    int len_table = table_len(order);
    char **new_order;

    if ((order[0][0] == '>' || order[0][0] == '<')
    && ((order[0][1] == '\0' && len_table >= 3)
    || (order[0][1] != '\0' && len_table >= 2))) {
        new_order = parse_table(order);
        buffer = gather_table(new_order, ' ', 1);
        active_arrow_order(new_order, info, buffer);
        table_free(new_order);
    } else {
        buffer = gather_table(order, ' ', 1);
        active_arrow_order(order, info, buffer);
    }
    free(buffer);
}
