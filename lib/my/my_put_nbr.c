/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** my_put_nbr.c
*/

#include "../../include/my.h"

int show_finish(int nb)
{
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return (0);
    } else {
        return (1);
    }
}

int my_put_nbr(int nb)
{
    int num;

    if (show_finish(nb) == 0)
        return (0);
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb < 10) {
            my_putchar(48 + nb % 10);
        } else {
            num = (nb % 10);
            nb = (nb - num) / 10;
            my_put_nbr(nb);
            my_putchar(48 + num);
        }
    }
    return (0);
}
