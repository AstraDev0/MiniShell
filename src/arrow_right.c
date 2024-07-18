/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** arrow_right
*/

#include "my.h"

int prosess_file_inject(prss_t *pros, int check_odr, int oflag, shell_a *info)
{
    pid_t pid = fork();
    int status = 0;
    int file_desc = 0;
    if (pid == -1) {
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
    } else {
        if (check_odr != 1) {
            file_desc = open(pros->table_buffer_rm_space[0], oflag, 0644);
            dup2(file_desc, 1);
        }
        if (check_odr == 1
        || active_arrow_left(info, pros->table_words, pros->cut_left_arrow))
            display_results(info, pros->table_words);
        if (check_odr != 1)
            close(file_desc);
        exit(info->terminal == 0 ? info->status * -1 : info->status);
    }
    return status_update(status, info);
}

void rdt_file_inject(shell_a *info, char *buffer_gather, int oflag)
{
    prss_t prosess;
    int check_odr = 0;
    char **get_no_space;

    prosess.cut_left_arrow = my_split(buffer_gather, "<");
    prosess.table_buffer = my_split(prosess.cut_left_arrow[0], ">");
    prosess.table_buffer_rm_space = my_split(prosess.table_buffer[1], " \t");
    get_no_space = my_split(prosess.table_buffer[0], " \t");
    check_odr = check_order(get_no_space, info);
    prosess.table_words = create_table_ord(my_split(prosess.cut_left_arrow[0],
    ">"), NULL);
    if (prosess_file_inject(&prosess, check_odr, oflag, info) == 0)
        info->terminal = 0;
    table_free(prosess.table_buffer);
    table_free(prosess.table_buffer_rm_space);
    table_free(prosess.cut_left_arrow);
    table_free(prosess.table_words);
    table_free(get_no_space);
}

int choise_file_add_move(shell_a *info, char **get_val, int file_desc_2)
{
    if (info->ar_right == 1)
        file_desc_2 = open(get_val[0], O_CREAT | O_RDWR
    | O_TRUNC, 0644);
    if (info->ar_right == 4)
        file_desc_2 = open(get_val[0], O_CREAT | O_RDWR
    | O_APPEND, 0644);
    return file_desc_2;
}

int active_arrow_right(shell_a *info, char **table_words, char **cut_right_ar)
{
    char **get_val;
    int file_desc_2 = 0;
    char **new_table_words;

    if ((info->ar_right == 1 || info->ar_right == 4)
    && table_len(cut_right_ar) > 1) {
        get_val = my_split(cut_right_ar[1], " \t");
        file_desc_2 = choise_file_add_move(info, get_val, file_desc_2);
        dup2(file_desc_2, 1);
        close(file_desc_2);
        new_table_words = create_new_table(table_words, get_val);
        display_results(info, new_table_words);
        table_free(get_val);
        free(new_table_words);
        return 0;
    }
    return 1;
}
