/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** check_arrows
*/

#include "my.h"

int check_condition_ar(char *buffer, char c, char letter, int count_table)
{
    if (count_table == 1 || count_table > 2
    || (count_table - 1 < count_only_solo_c(buffer, c)
    && count_table - 1 > count_dubble_value(buffer, c))
    || letter == c || check_more(buffer, c) != 0
    || redirection_glue(buffer, c))
        return 1;
    return 0;
}

int check_arrows(char *buffer, char c, char letter, int count_table)
{
    int res = 0;
    int count = count_value(buffer, c);

    if (check_condition_ar(buffer, c, letter, count_table)) {
        if (count >= 1)
            res = 2;
        if (count >= 1
        && letter == c && count < 3 || check_more(buffer, c) != 0
        || redirection_glue(buffer, c))
            res = 3;
    } else {
        if (count_dubble_value(buffer, c) > count_only_solo_c(buffer, c))
            res = 4;
        else
            res = 1;
    }
    return res;
}
