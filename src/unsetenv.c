/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** unsetenv.c
*/

#include "my.h"

void check_match_words(char **words, shell_a *info, int i, int *pass)
{
    int len = 0;

    for (int d = 1; words[d] != 0; d++) {
        len = my_strlen(words[d]);
        if (my_strcmp_custom(info->envp[i], words[d]) == len
        && info->envp[i][len] == '=') {
            *pass = *pass + 1;
            break;
        }
    }
}

int end_unsetenv(char **buff, shell_a *info, int count)
{
    buff[count] = NULL;
    info->envp = buff;
    return 0;
}

int unset_env(char **words, shell_a *info)
{
    int i = 0;
    int count = 0;
    int pass = 0;
    char **buff = malloc(sizeof(char *) * (table_len(info->envp) + 1));

    if (table_len(words) == 1)
        write(2, "unsetenv: Too few arguments.\n", 30);
    for (i; info->envp[i] != 0; i++) {
        pass = 0;
        check_match_words(words, info, i, &pass);
        if (pass) {
            free(info->envp[i]);
            continue;
        }
        buff[count] = info->envp[i];
        count++;
    }
    return end_unsetenv(buff, info, count);
}
