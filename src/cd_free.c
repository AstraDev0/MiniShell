/*
** EPITECH PROJECT, 2022
** cd freeing function
** File description:
** cd_free
*/

#include "my.h"

int free_dubble_buff(char *buff, char *path_buff)
{
    free(buff);
    free(path_buff);
    return 0;
}
