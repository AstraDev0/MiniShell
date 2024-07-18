/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** detect_first_redirection
*/

#include "my.h"

void detect_first_rdt(char **words, int detect, shell_a *info, char *buffer)
{
    if ((info->ar_right != 1 && info->ar_right != 4)
    || (info->ar_left != 1 && info->ar_left != 4))
        info->status = display_erros_arrows(info->ar_right >= info->ar_left
        ? info->ar_right : info->ar_left, info);
    if (detect == '<')
        arrow_left_act(words, info, buffer);
    if (detect == '>')
        arrow_right_act(words, info, buffer);
}

int detect_first_arrow(char *buffer_gather)
{
    for (int i = 0; buffer_gather[i]; i++) {
        if (buffer_gather[i] == '>' || buffer_gather[i] == '<')
            return buffer_gather[i];
    }
    return 0;
}
