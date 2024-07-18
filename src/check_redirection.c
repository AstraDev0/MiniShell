/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** check_redirection
*/

#include "../include/my.h"

int check_more(char *buffer, char c)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == c && buffer[i + 1] == c
        && i != 0 && buffer[i - 1] == c)
            count++;
    return count;
}

int check_arrow(char *buffer, char c, int res)
{
    char conv_val[2] = {c, 0};
    char **table = my_split(buffer, conv_val);
    int count_table = table_len(table);
    char **split_table = my_split(buffer, " \t");
    int len_table = table_len(split_table) - 1;
    int len_str = my_strlen(split_table[len_table]) - 1;
    char letter = split_table[len_table][len_str];

    res = check_arrows(buffer, c, letter, count_table);
    table_free(table);
    table_free(split_table);
    return res;
}

char *check_arrow_main(char **words, int *ar_right, int *ar_left)
{
    char *buffer;
    int count_table = 0;

    buffer = gather_table(words, ' ', 1);
    *ar_right = check_arrow(buffer, '>', *ar_right);
    *ar_left = check_arrow(buffer, '<', *ar_left);

    if (*ar_right == 2 || *ar_right == 3)
        *ar_left = *ar_right;
    if (*ar_left == 2 || *ar_left == 3)
        *ar_right = *ar_left;
    return buffer;
}

void active_arrow_order(char **words, shell_a *info, char *buffer)
{
    char *buffer_gather;
    int detect = 0;

    info->ar_right = 0;
    info->ar_left = 0;
    buffer_gather = check_arrow_main(words, &info->ar_right, &info->ar_left);
    detect = detect_first_arrow(buffer);
    detect_first_rdt(words, detect, info, buffer);
    if (info->ar_right == 0 && info->ar_left == 0)
        display_results(info, words);
    free(buffer_gather);
}
