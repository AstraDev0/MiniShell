/*
** EPITECH PROJECT, 2022
** setenv checks and error handling
** File description:
** setenv_check
*/

#include "my.h"

int set_env_check_error_next(char **words)
{
    for (int i = 0; words[1][i] != '\0'; i++) {
        if (words[1] != 0 && !((words[1][i] >= 97 && words[1][i] <= 122)
        || (words[1][i] >= 65 && words[1][i] <= 90)
        || (words[1][i] >= 48 && words[1][i] <= 57))) {
            write(2, "setenv: Variable name must contain \
alphanumeric characters.\n", 61);
            return 84;
        }
    }
    return 0;
}

int set_env_check_error(char **words)
{
    if (words[1] == 0)
        return 0;
    if (table_len(words) > 3) {
        write(2, "setenv: Too many arguments.\n", 29);
        return 84;
    }
    if (words[1] != 0 && !((words[1][0] >= 97 && words[1][0] <= 122)
    || (words[1][0] >= 65 && words[1][0] <= 90))) {
        write(2, "setenv: Variable name must begin with a letter.\n", 49);
        return 84;
    }
    return set_env_check_error_next(words);
}

int set_env_check(char **words, shell_a *info, int count_mal)
{
    if (set_env_check_error(words) == 84)
        return 1;
    if (count_mal == 1) {
        display_env(info);
        return 0;
    }
    if (count_mal == 2) {
        if (env_arg_exists(info->envp, words[1]))
            set_env(info, words, count_mal);
        return 0;
    }
    if (count_mal == 3) {
        if (env_arg_exists(info->envp, words[1]) == 0)
            replace_env(words, info);
        else
            set_env(info, words, count_mal);
    }
    return 0;
}
