/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf.c
*/

#include "../../include/my.h"

void start(va_list ap, int str_1, int forward_str_1, int indicator)
{
    if (params(str_1, forward_str_1) == 1)
        my_putchar(va_arg(ap, int));
    if (params(str_1, forward_str_1) == 2)
        my_putstr(va_arg(ap, char *));
    if (params(str_1, forward_str_1) == 3 && indicator != '+')
        my_put_nbr(va_arg(ap, int));
    if (params(str_1, forward_str_1) == 3 && indicator == '+')
        display_d_plus(va_arg(ap, int));
    if (params(str_1, forward_str_1) == 4)
        display_big_s(va_arg(ap, char *));
    if (params(str_1, forward_str_1) == 5)
        my_put_nbr_unsigned(va_arg(ap, unsigned int));
    start_next(ap, str_1, forward_str_1, indicator);
}

void start_next(va_list ap, int str_1, int forward_str_1, int indicator)
{
    if (params(str_1, forward_str_1) == 6 && indicator != '#')
        display_x(0, va_arg(ap, unsigned int));
    if (params(str_1, forward_str_1) == 7 && indicator != '#')
        display_x(1, va_arg(ap, unsigned int));
    if (params(str_1, forward_str_1) == 6 && indicator == '#')
        display_x_hashtag(0, va_arg(ap, unsigned int));
    if (params(str_1, forward_str_1) == 7 && indicator == '#')
        display_x_hashtag(1, va_arg(ap, unsigned int));
    if (params(str_1, forward_str_1) == 8 && indicator != '#')
        my_putoctal(va_arg(ap, unsigned int));
    if (params(str_1, forward_str_1) == 8 && indicator == '#')
        display_o_hashtag(va_arg(ap, unsigned int));
    if (params(str_1, forward_str_1) == 9)
        display_p(va_arg(ap, long long));
}

int re_indicator(char *str, int indicator)
{
    if (str[indicator] == '#')
        return '#';
    if (str[indicator] == '+')
        return '+';
    if (str[indicator] == ' ')
        return ' ';
    if (str[indicator] == '0')
        return '0';
    if (str[indicator] == '.')
        return '.';
    if (str[indicator] == '-')
        return '-';
    if (str[indicator] >= 48 && str[indicator] <= 57)
        return str[indicator];
    return 0;
}

int check_indicator(char *str, int *indicator, int *i, int *indicator_2)
{
    int origin = *indicator;
    int j = *i;
    int count_j = 0;
    int pass = 0;

    for (j; str[j] != '\0'; j++) {
        if (re_indicator(str, j) != 0 && str[*i] == '%') {
            *indicator = *indicator + 1;
            *indicator_2 = *indicator_2 + 1;
            count_j = j;
            pass = 1;
        }
        if (pass == 1 && re_indicator(str, j + 1) == 0 && str[*i] == '%')
            break;
    }
    if (re_indicator(str, count_j) != 0 && params(str[count_j + 1], '%') == 0)
        *indicator = origin;
    return re_indicator(str, count_j);
}

int my_printf(char *str_1, ...)
{
    va_list ap;
    int a = 0;
    int indicator = 0;
    int indicator_2 = 0;
    int value = 0;
    int memory = 0;

    va_start(ap, str_1);
    for (int i = 0; str_1[i + indicator] != '\0'; i++) {
        value = check_indicator(str_1, &indicator, &i, &indicator_2);
        if (value != 0)
            memory = value;
        a = display_big_str(a, str_1, i, &indicator);
        if (a == 0)
            indicator_2 = 0;
        start(ap, str_1[i + indicator_2], str_1[i - 1], memory);
    }
    va_end(ap);
    return (0);
}
