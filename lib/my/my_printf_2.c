/*
** EPITECH PROJECT, 2021
** my_printf_2.c
** File description:
** my_printf_2.c
*/

#include "../../include/my.h"

void display_big_s(char *str_2)
{
    for (int i = 0; i <= my_strlen(str_2); i++) {
        if (str_2[i] >= 127 || str_2[i] < 32 && str_2[i] != '\0') {
            my_putchar('\\');
            my_putchar('0');
            my_putchar('0');
            my_putoctal(str_2[i]);
        } else {
            my_putchar(str_2[i]);
        }
    }
}

void display_x(int maj, long long nbr)
{
    if (nbr < 0) {
        nbr = -nbr;
        my_putchar('-');
    }
    if (nbr >= 16)
        display_x(maj, nbr / 16);
    if (maj == 0 && nbr % 16 >= 10)
        my_putchar(nbr % 16 + 'W');
    else if (maj == 1 && nbr % 16 >= 10)
        my_putchar(nbr % 16 + '7');
    else
        my_putchar(nbr % 16 + '0');
}

void display_p(long long num)
{
    my_putstr("0x");
    display_x(0, num);
}

int my_putoctal(unsigned int nb)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb >= 0 && nb <= 7) {
        my_putchar(nb + '0');
    } else if (nb > 7) {
        my_putoctal(nb / 8);
        my_putchar((nb % 8) + '0');
    }
    return (0);
}

void display_o_hashtag(unsigned int arg)
{
    my_putstr("0");
    my_putoctal(arg);
}
