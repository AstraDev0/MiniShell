/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** order.c
*/

#include "my.h"

int check_order(char **words, shell_a *info)
{
    char *buffer = get_exec_cmd(words[0], info);

    if (buffer != NULL) {
        free(buffer);
        return 4;
    }
    free(buffer);
    if (!my_strcmp(words[0], "exit"))
        return 0;
    if (!my_strcmp(words[0], "cd"))
        return 2;
    if (!my_strcmp(words[0], "pwd"))
        return 3;
    if (!my_strcmp(words[0], "setenv"))
        return 5;
    if (!my_strcmp(words[0], "unsetenv"))
        return 6;
    return 1;
}

int get_pwd(shell_a *info, char **words)
{
    char tampon[UCHAR_MAX];

    if (getcwd(tampon, UCHAR_MAX) == NULL)
        return 1;
    if (table_len(words) > 1)
        write(2, "pwd: ignoring non-option arguments\n", 36);
    my_printf("%s\n", tampon);
    return 0;
}

void set_env_add(char **words, char **resp, int i)
{
    int len_2 = my_strlen(words[2]);
    char *buff;

    buff = malloc(sizeof(char) * (my_strlen(words[1]) + len_2 + 2));
    resp[i] = malloc(sizeof(char) * (my_strlen(words[1]) + len_2 + 2));
    my_strcpy(buff, words[1]);
    my_strcat(buff, "=");
    my_strcat(buff, words[2]);
    my_strcpy(resp[i], buff);
    free(buff);
}

void set_env(shell_a *info, char **words, int count_mal)
{
    int i = 0;
    char **resp = malloc(sizeof(char *) * (table_len(info->envp) + 3));
    char *buff;

    for (i; info->envp[i] != 0; i++)
        resp[i] = info->envp[i];
    if (count_mal == 3) {
        set_env_add(words, resp, i);
    } else if (count_mal == 2) {
        buff = malloc(sizeof(char) * (my_strlen(words[1]) + 2));
        my_strcpy(buff, words[1]);
        my_strcat(buff, "=");
        resp[i] = buff;
    }
    resp[i + 1] = NULL;
    info->envp = resp;
}

void display_results(shell_a *info, char **words)
{
    int count_mal = table_len(words);
    int res = check_order(words, info);

    if (res == 0)
        info->status = exit_or_print_exit(words, info);
    if (res == 1)
        info->status = command_exec(words, 1, info);
    if (res == 2)
        info->status = cd_with_err(words, info);
    if (res == 3)
        info->status = get_pwd(info, words);
    if (res == 4)
        info->status = command_exec(words, 0, info);
    if (res == 5)
        info->status = set_env_check(words, info, count_mal);
    if (res == 6)
        info->status = unset_env(words, info);
}
