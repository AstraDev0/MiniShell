/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** display_error
*/

#include "my.h"

int display_error_pmt(char *val, int num)
{
    if (num == 1) {
        write(2, val, my_strlen(val));
        write(2, ": Permission denied.\n",
        my_strlen(": Permission denied.\n"));
    }
    if (num == 2) {
        write(2, "/usr/bin/", my_strlen("/usr/bin/"));
        write(2, val, my_strlen(val));
        write(2, ": File name too long.\n",
        my_strlen(": File name too long.\n"));
    }
    return 84;
}

int err_not_fount_command(char **argv)
{
    char buff[] = ": Command not found.\n";

    write(2, argv[0], my_strlen(argv[0]));
    write(2, buff, my_strlen(buff));
    return 84;
}

int error_no_directory(char *err)
{
    char buff[] = ": Not a directory.\n";

    write(2, err, my_strlen(err));
    write(2, buff, my_strlen(buff));
    return 84;
}

int error_permission(char *err)
{
    char buff[] = ": Permission denied.\n";

    write(2, err, my_strlen(err));
    write(2, buff, my_strlen(buff));
    return 84;
}

int error_directory(char *err)
{
    char buff[] = ": No such file or directory.\n";

    write(2, err, my_strlen(err));
    write(2, buff, my_strlen(buff));
    return 84;
}
