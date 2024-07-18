/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** cd.c
*/

#include "my.h"

int cd_error(char **words)
{
    if (table_len(words) > 2) {
        if (words[1] && !my_strcmp(words[1], "-"))
            write(2, "Usage: cd [-plvn][-|<dir>].\n", 29);
        else
            write(2, "cd: Too many arguments.\n", 25);
        return 84;
    }
    return 0;
}

int get_env_nbr(char **envp, char *src)
{
    int len = my_strlen(src);
    int p = 0;

    for (int i = 0; envp[i] != 0; i++) {
        if (my_strcmp_custom(envp[i], src) != len || envp[i][len] != '=')
            continue;
        for (int v = len + 1; envp[i][v] != '\0'; v++)
            p++;
        return p;
    }
    return p;
}

int minus_cd(char **words, shell_a *info)
{
    char *buffer;

    if (words[1] && !my_strcmp(words[1], "-")) {
        buffer = getcwd(NULL, 0);
        chdir(info->forward);
        info->forward != NULL ? free(info->forward) : 0;
        info->forward = buffer;
        return 1;
    }
    return 0;
}

int cd_with_err_next(char **words, char *buff, shell_a *info)
{
    char *path_buff = getcwd(NULL, 0);

    if (check_val_home(words, buff, info) || minus_cd(words, info))
        return free_dubble_buff(buff, path_buff);
    if (chdir(words[1]) == -1) {
        error_directory(words[1]);
        free(buff);
        free(path_buff);
        return 1;
    } else {
        info->forward != NULL ? free(info->forward) : 0;
        info->forward = path_buff;
        free(buff);
        return 0;
    }
    return free_dubble_buff(buff, path_buff);
}

int cd_with_err(char **words, shell_a *info)
{
    char *buff;
    int d = 0;
    if (cd_error(words) == 84)
        return 1;
    buff = malloc(sizeof(char) * (get_env_nbr(info->envp, "HOME") + 1));
    get_env(info->envp, buff, "HOME");
    if (condition_error_check(buff, words, info) == 84) {
        free(buff);
        return 1;
    }
    return cd_with_err_next(words, buff, info);
}
