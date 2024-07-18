/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** error_redirections
*/

#include "my.h"

int display_erros_arrows(int err, shell_a *info)
{
    if (err == 2) {
        write(2, "Ambiguous output redirect.\n", 28);
        return 1;
    }
    if (err == 3) {
        write(2, "Missing name for redirect.\n", 28);
        return 1;
    }
    return 0;
}
