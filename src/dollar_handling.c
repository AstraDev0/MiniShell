/*
** EPITECH PROJECT, 2022
** handling the $ in shell
** File description:
** dollar_handling
*/

#include "my.h"

int found_dollar(char *split_space)
{
    for (int i = 0; split_space[i]; i++) {
        if (split_space[i] == '$' && split_space[i + 1]
        && split_space[i + 1] != '\0' && split_space[i + 1] != '$')
            return 1;
    }
    return 0;
}

int split_table_dollar_tb(char **split_dollar, char **res, int i, char *status)
{
    char *get_env_dollar = getenv(split_dollar[i]);

    if (get_env_dollar == NULL && split_dollar[i][0] == '?')
        get_env_dollar = status;
    if (get_env_dollar == NULL) {
        write(2, split_dollar[i], my_strlen(split_dollar[i]));
        write(2, ": Undefined variable.\n", 23);
        table_free(split_dollar);
        res[i] = NULL;
        table_free(res);
        return 0;
    } else {
        res[i] = malloc(sizeof(char) * (my_strlen(get_env_dollar) + 1));
        my_strcpy(res[i], get_env_dollar);
    }
    return 1;
}

char *split_table_dollar(char *split_space, char *status, char *res_st, int i)
{
    char **split_dollar = my_split(split_space, "$");
    int start_dollar = split_space[0] == '$' ? 0 : 1;
    char **res = malloc(sizeof(char *)
    * ((table_len(split_dollar) - (start_dollar == 0 ? 1 : 0)) + 2));
    for (i; split_dollar[i]; i++) {
        if (start_dollar) {
            start_dollar = 0;
            res[i] = malloc(sizeof(char) * (my_strlen(split_dollar[i]) + 1));
            my_strcpy(res[i], split_dollar[i]);
            continue;
        }
        if (!split_table_dollar_tb(split_dollar, res, i, status))
            return 0;
    }
    res[i] = NULL;
    table_free(split_dollar);
    res_st = gather_table(res, ' ', 0);
    table_free(res);
    return res_st;
}

int loop_dollar(char **split_space, char **table_res, int i, char *status)
{
    char *split_dollar_res;

    if (found_dollar(split_space[i])) {
        split_dollar_res = split_table_dollar(split_space[i], status, NULL, 0);
        if (split_dollar_res == NULL) {
            table_res[i] = NULL;
            table_free(split_space);
            table_free(table_res);
            return 0;
        }
        table_res[i] = split_dollar_res;
    } else {
        table_res[i] = malloc(sizeof(char) * (my_strlen(split_space[i]) + 1));
        my_strcpy(table_res[i], split_space[i]);
    }
    return 1;
}

char *dollar_insert(char *buffer, char *status)
{
    char **split_space = my_split(buffer, " \t");
    char **table_res = malloc(sizeof(char *) * (table_len(split_space) + 1));
    char *result;
    int i = 0;

    for (i; split_space[i]; i++)
        if (!loop_dollar(split_space, table_res, i, status))
            return NULL;
    table_free(split_space);
    table_res[i] = NULL;
    result = gather_table(table_res, ' ', 1);
    table_free(table_res);
    return result;
}
