/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** getenv.c
*/

#include "my.h"

char *get_env(char **envp, char *resp, char *src)
{
    int len = my_strlen(src);
    int p = 0;

    for (int i = 0; envp[i] != 0; i++) {
        if (my_strcmp_custom(envp[i], src) != len || envp[i][len] != '=')
            continue;
        for (int v = len + 1; envp[i][v] != '\0'; v++) {
            resp[p] = envp[i][v];
            p++;
        }
        resp[p] = '\0';
        return resp;
    }
    return NULL;
}

void display_env(shell_a *info)
{
    for (int i = 0; info->envp[i] != 0; i++)
        my_printf("%s\n", info->envp[i]);
}

int err_env(char **argv)
{
    int len = my_strlen(argv[1]);
    char *buff = malloc(sizeof(char) * (len + 42));

    my_strcpy(buff, "env: ‘");
    my_strcat(buff, argv[1]);
    my_strcat(buff, "’: No such file or directory\n");
    write(2, buff, my_strlen(buff));
    free(buff);
    return 84;
}

int exception_exec(char **argv, shell_a *info)
{
    char *buffer = get_exec_cmd(argv[0], info);

    if (buffer != NULL && my_strcmp(argv[0], "env") == 0) {
        if (table_len(argv) > 1)
            err_env(argv);
        else
            display_env(info);
        free(buffer);
        return 0;
    } else if (buffer != NULL && access(buffer, F_OK) == 0) {
        execve(buffer, argv, info->envp);
        free(buffer);
        _exit(EXIT_FAILURE);
        return 0;
    }
    buffer != NULL ? free(buffer) : 0;
    return 1;
}
