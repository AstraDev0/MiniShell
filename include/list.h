/*
** EPITECH PROJECT, 2021
** list.h
** File description:
** list.h
*/

#ifndef LIST_H_
    #define LIST_H_

typedef struct shell_a {
    int terminal;
    char **envp;
    int ar_right;
    int ar_left;
    int status;
    char *forward;
}shell_a;

typedef struct prss_t {
    char **cut_left_arrow;
    char **table_buffer;
    char **table_buffer_rm_space;
    char **table_words;
}prss_t;

#endif /* !list_h */
