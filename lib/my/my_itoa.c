/*
** EPITECH PROJECT, 2021
** my_itoa.c
** File description:
** my_itoa.c
*/

#include "../../include/my.h"

char *my_itoa(int num)
{
    int nbr = my_intlen(num);
    char *str = malloc(sizeof(char) * (nbr + 1));

    if (num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    str[nbr] = '\0';
    nbr--;
    for (nbr; nbr >= 0; nbr--) {
        str[nbr] = num % 10 + 48;
        num = num / 10;
    }
    return (str);
}
