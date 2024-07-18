/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** utils.c
*/

#include "my.h"

void my_free_tab(char **tab)
{
    int rk = -1;

    while (tab[++rk])
        free(tab[rk]);
    free(tab[rk]);
}

int my_strcmp_custom(char const *s1, char const *s2)
{
    int i = 0;

    while ((s1[i] != '\0') && (s1[i] == s2[i]) && (s2[i] != '\0'))
        i++;
    return (i);
}

int check_space(char *buffer)
{
    for (int i = 0; buffer[i] != 0; i++)
        if (buffer[i] != ' ' && buffer[i] != '\t')
            return 1;
    return 0;
}

int env_arg_exists(char **envp, char *search)
{
    int len = my_strlen(search);

    for (int i = 0; envp[i] != 0; i++) {
        if (my_strcmp_custom(envp[i], search) != len || envp[i][len] != '=')
            continue;
        return 0;
    }
    return 1;
}

int table_len(char **string)
{
    int i = 0;

    for (i; string[i] != 0; i++);
    return i;
}
