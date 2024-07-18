/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** arrow_left_redirection
*/

#include "my.h"

int open_file_or_error(shell_a *info, int oflag, char **table_buffer)
{
    int file_desc = 0;
    char **table_val_l = my_split(table_buffer[1], " \t");

    if (access(table_val_l[0], F_OK) == -1) {
        error_directory(table_val_l[0]);
        table_free(table_val_l);
        return -1;
    }
    if (access(table_val_l[0], R_OK) == -1) {
        error_permission(table_val_l[0]);
        table_free(table_val_l);
        return -1;
    }
    file_desc = open(table_val_l[0], oflag, 0644);
    if (file_desc != -1)
        dup2(file_desc, STDIN_FILENO);
    table_free(table_val_l);
    return file_desc;
}

int prosess_rdt_order(prss_t *pros, int check_odr, int oflag, shell_a *info)
{
    pid_t pid = fork();
    int status = 0;
    int file_desc = 0;
    if (pid == -1) {
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
    } else {
        if (check_odr != 1)
            file_desc = open_file_or_error(info, oflag, pros->table_buffer);
        file_desc == -1 ? exit(1) : 0;
        if (check_odr == 1
        || active_arrow_right(info, pros->table_words, pros->cut_left_arrow))
            display_results(info, pros->table_words);
        check_odr != 1 && file_desc != -1 ? close(file_desc) : 0;
        exit(info->terminal == 0 ? info->status * -1 : info->status);
    }
    return status_update(status, info);
}

void rdt_order(shell_a *info, char *buffer_gather)
{
    prss_t prosess;
    int check_odr = 0;

    prosess.cut_left_arrow = my_split(buffer_gather, ">");
    prosess.table_buffer = my_split(prosess.cut_left_arrow[0], "<");
    prosess.table_buffer_rm_space = my_split(prosess.table_buffer[0], " \t");
    check_odr = check_order(prosess.table_buffer_rm_space, info);
    prosess.table_words = create_table_ord(my_split(prosess.cut_left_arrow[0],
    "<"), NULL);
    if (prosess_rdt_order(&prosess, check_odr, O_RDONLY, info) == 0)
        info->terminal = 0;
    table_free(prosess.table_buffer);
    table_free(prosess.table_buffer_rm_space);
    table_free(prosess.cut_left_arrow);
    table_free(prosess.table_words);
}

void arrow_right_act(char **words, shell_a *info, char *buffer_gather)
{
    if (info->ar_right == 1)
        rdt_file_inject(info, buffer_gather, O_CREAT | O_RDWR
        | O_TRUNC);
    if (info->ar_right == 4)
        rdt_file_inject(info, buffer_gather, O_CREAT | O_RDWR
        | O_APPEND);
}

void arrow_left_act(char **words, shell_a *info, char *buffer_gather)
{
    if (info->ar_left == 1)
        rdt_order(info, buffer_gather);
    if (info->ar_left == 4)
        NULL;
}
