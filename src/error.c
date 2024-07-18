/*
** EPITECH PROJECT, 2022
** error.c
** File description:
** error.c
*/

#include "my.h"

int check_perm(char **words)
{
    if (words[1] != 0 && access(words[1], EACCES) == -1
    && access(words[1], X_OK) == -1 && access(words[1], W_OK) == -1
    && access(words[1], W_OK) == -1 && check_directory(words[1]) == 0
    && my_strcmp(words[1], "~") != 0 && access(words[1], F_OK) == 0
    && my_strcmp(words[1], "--") != 0 && my_strcmp(words[1], "-") != 0)
        return 1;
    return 0;
}

int minus_cd_err(char **words, shell_a *info)
{
    if (info->forward == NULL) {
        write(2, ": No such file or directory.\n", 30);
        return 1;
    }
    return 0;
}

int check_exist(char **words)
{
    if (words[1] && my_strcmp(words[1], "~")
    && my_strcmp(words[1], "--") && my_strcmp(words[1], "-"))
        return 1;
    return 0;
}

int condition_error_check(char *buff, char **words, shell_a *info)
{
    if (check_perm(words))
        return error_permission(words[1]);
    if (words[1] != 0 && !my_strcmp(words[1], "-")
    && minus_cd_err(words, info))
        return 84;
    if (words[1] != 0 && check_long(words[1]) && check_exist(words))
        return display_error_pmt(words[1], 2);
    if (words[1] != 0 && access(words[1], F_OK) == -1 && check_exist(words))
        return error_directory(words[1]);
    if (words[1] != 0 && (my_strcmp(words[1], "~") == 0
    || my_strcmp(words[1], "--") == 0) && access(buff, R_OK) == -1)
        return display_error_pmt(buff, 1);
    if (words[1] != 0 && access(words[1], R_OK) == -1 && check_exist(words))
        return display_error_pmt(words[1], 1);
    if (words[1] != 0 && check_directory(words[1]) == 0 && check_exist(words))
        return error_no_directory(words[1]);
    return 0;
}
