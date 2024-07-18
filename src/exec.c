/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** exec.c
*/

#include "my.h"

int error_exec_display_and_exeption(char **argv, shell_a *info)
{
    if (check_directory(argv[0]))
        return display_error_pmt(argv[0], 1);
    if (exception_exec(argv, info)) {
        if (check_long(argv[0]))
            return display_error_pmt(argv[0], 2);
        if (access(argv[0], F_OK) == -1)
            return err_not_fount_command(argv);
        if (access(argv[0], X_OK) == -1)
            return display_error_pmt(argv[0], 1);
        execve(argv[0], argv, info->envp);
    }
    return 84;
}

int command_exec(char **argv, int err, shell_a *info)
{
    pid_t parent = getpid();
    pid_t pid = fork();
    int status = 0;
    if (pid == -1) {
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
    } else {
        if (error_exec_display_and_exeption(argv, info) == 84) {
            _exit(EXIT_FAILURE);
            return 1;
        }
        if (err == 1) {
            err_not_fount_command(argv);
            _exit(EXIT_FAILURE);
            return 1;
        }
        return 0;
    }
    return status % 255;
}
