/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** replace_value_and_error.c
*/

#include "my.h"

char env_raplace_add_value(char **words, char **resp, int i, shell_a *info)
{
    int len_1 = my_strlen(words[1]);
    int len_2 = my_strlen(words[2]);
    char *buff;

    buff = malloc(sizeof(char) * (len_1 + len_2 + 2));
    resp[i] = malloc(sizeof(char) * (len_1 + len_2 + 2));
    my_strcpy(buff, words[1]);
    my_strcat(buff, "=");
    my_strcat(buff, words[2]);
    my_strcpy(resp[i], buff);
    free(buff);
    free(info->envp[i]);
}

void replace_env(char **words, shell_a *info)
{
    int len_1 = my_strlen(words[1]);
    char **resp = malloc(sizeof(char *) * (table_len(info->envp) + 2));
    int i = 0;

    for (i; info->envp[i] != 0; i++) {
        if (my_strcmp_custom(info->envp[i], words[1]) != len_1
        || info->envp[i][len_1] != '=') {
            resp[i] = info->envp[i];
        } else {
            env_raplace_add_value(words, resp, i, info);
        }
    }
    resp[i] = malloc(1);
    resp[i] = 0;
    info->envp = resp;
}

int check_num(char *buff)
{
    int check = 1;

    for (int i = 0; buff[i]; i++) {
        if (buff[i] <= 57 && buff[i] >= 48)
            check = 0;
    }
    return !check;
}

int exit_or_print_exit_next(char **words, shell_a *info)
{
    if (my_strcmp(words[1], "-t") == 0 && words[2] == 0) {
        write(2, "exit: Missing file name.\n", 26);
        return 1;
    }
    if (my_strcmp(words[1], "-t") == 0 && words[2] != 0) {
        write(2, "exit\n", 6);
        info->terminal = 0;
        return 1;
    }
    write(2, "exit: Expression Syntax.\n", 26);
    return 1;
}

int exit_or_print_exit(char **words, shell_a *info)
{
    if (words[1] != 0 && words[2] != 0 && words[3] != 0
    && (words[1][0] == '>' || words[1][0] == '<') && check_num(words[3])) {
        info->terminal = 0;
        return my_atoi(words[3]);
    }
    if (words[1] != 0 && check_num(words[1]) && words[2] == 0) {
        info->terminal = 0;
        return my_atoi(words[1]);
    }
    if (words[1] == 0 || words[1][0] == '>' || words[1][0] == '<') {
        info->terminal = 0;
        return 0;
    }
    return exit_or_print_exit_next(words, info);
}
