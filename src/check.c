/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** check.c
*/

#include "my.h"

int check_long(char *buff)
{
    int len = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] != '\\')
            len++;
        else
            len = 0;
        if (len > 255)
            return 1;
    }
    return 0;
}

int check_directory(char *file)
{
    DIR *dir;

    dir = opendir(file);
    if (dir == 0) {
        closedir(dir);
        return 0;
    }
    closedir(dir);
    return 1;
}

int check_val_home(char **words, char *buff, shell_a *info)
{
    if (words[1] == 0 || my_strcmp(words[1], "~") == 0
    || my_strcmp(words[1], "--") == 0) {
        info->forward != NULL ? free(info->forward) : 0;
        info->forward = getcwd(NULL, 0);
        chdir(buff);
        return 1;
    }
    return 0;
}
