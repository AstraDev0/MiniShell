/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** my_pwd
*/

#include "my.h"

char *get_var_env(void)
{
    char *buff;

    buff = getenv("HOST");
    if (buff == NULL)
        buff = getenv("USER");
    return buff == NULL ? "\0" : buff;
}

void str_insert(char *get_v, char *adress, char *pwd)
{
    my_strcpy(pwd, BLUE);
    if (get_v != "\0") {
        my_strcat(pwd, get_v);
        my_strcat(pwd, ":");
    }
    my_strcat(pwd, adress);
    my_strcat(pwd, "> ");
    my_strcat(pwd, WHITE);
}

char *my_pwd(void)
{
    int i = 0;
    int j = 0;
    char *adress;
    char *pwd;
    char *dir = getcwd(NULL, 0);
    char *get_v = get_var_env();

    for (i = my_strlen(dir); dir[i] != '/'; i--);
    adress = malloc(sizeof(char) * (my_strlen(dir) - i + 1));
    pwd = malloc(sizeof(char) * (my_strlen(dir)
    + my_strlen(get_v) - i + 21));
    for (j; dir[i] != '\0'; i++, j++)
        adress[j] = dir[i];
    adress[j] = '\0';
    str_insert(get_v, adress, pwd);
    free(adress);
    free(dir);
    return pwd;
}
