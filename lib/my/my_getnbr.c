/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** my_getnbr.c
*/

#include "../../include/my.h"
#include <stddef.h>

int result_for_nbr(int var, int mult, char const *str)
{
    while (*str != 0 && *str >= '0' && *str <= '9') {
        var = var * 10;
        var = var + *str - 48;
        str = str + 1;
    }
    var = var * mult;
    return (var);
}

int my_getnbr(char const *str)
{
    int var = 0;
    int i = 0;
    int mult = 0;

    if (str == NULL)
        return (-1);
    while ((*str < '0' || *str > '9') && *str != 0) {
        str = str + 1;
        i = i + 1;
    }
    if (i > 0 && *(str - 1) == '-')
        mult = -1;
    return (result_for_nbr(var, mult, str));
}
