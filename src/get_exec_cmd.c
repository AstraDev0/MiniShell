/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** get_exec_cmd
*/

#include "my.h"

void add_var(char *path_cmd, char **split_buff, int i, char *cmd)
{
    my_strcpy(path_cmd, split_buff[i]);
    my_strcat(path_cmd, "/");
    my_strcat(path_cmd, cmd);
}

char *get_exec_cmd(char *cmd, shell_a *info)
{
    char *buff = malloc(sizeof(char) * (get_env_nbr(info->envp, "PATH") + 1));
    char **split_buff;
    char *path_cmd = NULL;
    int ok = 0;
    int len = my_strlen(cmd);

    get_env(info->envp, buff, "PATH");
    split_buff = my_split(buff, ":");
    for (int i = 0; split_buff[i] && ok == 0; i++) {
        path_cmd = malloc(sizeof(char) * (my_strlen(split_buff[i]) + len + 2));
        add_var(path_cmd, split_buff, i, cmd);
        if (access(path_cmd, F_OK) == 0)
            break;
        free(path_cmd);
        path_cmd = NULL;
    }
    free(buff);
    table_free(split_buff);
    return path_cmd;
}
