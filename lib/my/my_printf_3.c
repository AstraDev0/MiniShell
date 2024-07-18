/*
** EPITECH PROJECT, 2021
** my_printf_3.c
** File description:
** my_printf_3.c
*/

#include "../../include/my.h"

unsigned int my_put_nbr_unsigned(unsigned int nb)
{
    int num;

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

int display_big_str(int a, char *str_1, int i, int *indicator)
{
    if (params(str_1[i + *indicator + 1], str_1[i]) != 0 && a == 0)
        a = *indicator + 2;
    if (a == 0) {
        my_putchar(str_1[i]);
    } else {
        a--;
    }
    if (*indicator > 0)
        *indicator = *indicator - 1;
    return a;
}

int params(int str_1, int forward_str_1)
{
    if ((str_1 == 'c' || str_1 == 'C') && forward_str_1 == '%')
        return 1;
    if (str_1 == 's' && forward_str_1 == '%')
        return 2;
    if ((str_1 == 'd' || str_1 == 'i') && forward_str_1 == '%')
        return 3;
    if (str_1 == 'S' && forward_str_1 == '%')
        return 4;
    if (str_1 == 'u' && forward_str_1 == '%')
        return 5;
    if (str_1 == 'x' && forward_str_1 == '%')
        return 6;
    if (str_1 == 'X' && forward_str_1 == '%')
        return 7;
    if (str_1 == 'o' && forward_str_1 == '%')
        return 8;
    if (str_1 == 'p' && forward_str_1 == '%')
        return 9;
    return 0;
}

void display_x_hashtag(int maj, unsigned int arg)
{
    if (maj == 1)
        my_putstr("0X");
    else
        my_putstr("0x");
    display_x(maj, arg);
}

void display_d_plus(int arg)
{
    if (arg >= 0)
        my_putchar('+');
    my_put_nbr(arg);
}
