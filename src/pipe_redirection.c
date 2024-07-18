/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** pipe_redirection
*/

#include "my.h"

void get_dup2(char ***order, int fd[])
{
    if (*(order + 1) != NULL)
        dup2(fd[1], 1);
}

int pipe_line(char ***order, shell_a *info, int status)
{
    int fd[2];
    pid_t pid;
    int fdd = 0;
    while (*order != NULL) {
        utils_loop(fd, &pid);
        if (pid == 0) {
            dup2(fdd, 0);
            get_dup2(order, fd);
            close(fd[0]);
            parse_redirection(*order, info);
            exit(info->terminal == 0 ? info->status * -1 : 0);
        } else {
            waitpid(pid, &status, 0);
            close(fd[1]);
            fdd = fd[0];
            order++;
        }
        status_update(status, info);
    }
}

void pipe_free(char ***split_s, char **split_p, char *table_m, char **words)
{
    for (int i = 0; split_s[i]; i++)
        table_free(split_s[i]);
    free(split_s);
    table_free(split_p);
    free(table_m);
    table_free(words);
}

void pipe_check(char **words, shell_a *info, char *buffer)
{
    char *table_merge = gather_table(words, ' ', 1);
    char **split_pipe = my_split(table_merge, "|");
    int count_table = table_len(split_pipe);
    char ***split_space = malloc(sizeof(char **) * count_table + 8);
    int i = 0;

    for (i; split_pipe[i]; i++)
        split_space[i] = my_split(split_pipe[i], " \t");
    split_space[i] = NULL;
    if (!my_strcmp(split_space[i - 1][0], "exit")
    || !my_strcmp(split_space[i - 1][0], "cd") || count_table == 1
    || !my_strcmp(split_space[0][0], "cat"))
        parse_redirection(split_space[i - 1], info);
    else
        check_valide_order(split_space, info);
    pipe_free(split_space, split_pipe, table_merge, words);
}
