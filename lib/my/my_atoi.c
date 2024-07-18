/*
** EPITECH PROJECT, 2021
** Epitech
** File description:
** my_atoi.c
*/

#include "../../include/my.h"

long long my_atoi(char *str)
{
    long long result = 0;
    int i = 0;

    if (str[0] == '-' && str[1] != '\0')
        i++;
    for (i; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        result = result + str[i] - '0';
        result = result * 10;
    }
    result = result / 10;
    if (str[0] == '-')
        return (result * -1);
    else
        return (result);
}
