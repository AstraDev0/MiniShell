/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** mnishell1.c
*/

#include "my.h"

void start_minishell_main(shell_a *info, char *buffer)
{
    char *quotation_buffer = remove_quotation_mark(buffer);
    char *status = my_itoa(info->status);
    char *dollar_i = dollar_insert(quotation_buffer, status);

    dollar_i != NULL ? separator_mix(info, dollar_i) : (info->status = 1);
    if (dollar_i != NULL)
        free(dollar_i);
    free(quotation_buffer);
    free(status);
}

void sigint(int a)
{
    char *buffer_pwd = my_pwd();

    my_printf("\n%s", buffer_pwd);
    free(buffer_pwd);
}

void add_envp_table(char **envp, shell_a *info)
{
    int i = 0;

    info->envp = malloc(sizeof(char *) * (table_len(envp) + 1));
    for (i; envp[i] != 0; i++) {
        info->envp[i] = malloc(sizeof(char) * my_strlen(envp[i]) + 1);
        my_strcpy(info->envp[i], envp[i]);
    }
    info->envp[i] = NULL;
}

int end_free(shell_a *info)
{
    table_free(info->envp);
    if (info->forward != NULL)
        free(info->forward);
    return 0;
}

int start_minishell(char **envp)
{
    char *buffer_pwd;
    shell_a info;
    size_t characters = 0;

    info.terminal = 1;
    info.status = 0;
    info.forward = NULL;
    add_envp_table(envp, &info);
    while (info.terminal && characters != -1) {
        signal(SIGINT, sigint);
        signal(SIGTSTP, sigint);
        buffer_pwd = my_pwd();
        if (isatty(0))
            printf("%s", buffer_pwd);
        free(buffer_pwd);
        characters = get_line(&info, characters);
    }
    return end_free(&info);
}
