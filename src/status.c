/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** status
*/

#include "my.h"

int status_update(int status, shell_a *info)
{
    if (status >= 63480) {
        info->status = status % 63480;
        info->terminal = 0;
    } else {
        info->status = status % 255;
    }
    return info->terminal;
}
