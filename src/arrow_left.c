/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** arrow_left
*/

#include "my.h"

char **create_new_table(char **table_words, char **get_val)
{
    char **new_table_words = malloc(sizeof(char *)
    * (table_len(table_words) + table_len(get_val)));
    int i = 0;
    int j = 0;

    for (i; table_words[i]; i++)
        new_table_words[i] = table_words[i];
    for (j; get_val[j]; j++) {
        if (j == 0) {
            i--;
            continue;
        }
        new_table_words[i + j] = get_val[j];
    }
    new_table_words[i + j] = NULL;
    return new_table_words;
}

void add_value_table(char **table_buffer, int *v, int i, char **table_result)
{
    char **space_cut = my_split(table_buffer[i], " \t");

    for (int j = 0; space_cut[j]; j++) {
        if (j == 0 && i == 1)
            continue;
        table_result[*v] = malloc(sizeof(char)
        * my_strlen(space_cut[j]) + 1);
        my_strcpy(table_result[*v], space_cut[j]);
        *v = *v + 1;
    }
    table_free(space_cut);
}

void space_and_table_free(char **space_c, char **space_c_2, char **table_b)
{
    table_free(space_c);
    table_free(space_c_2);
    table_free(table_b);
}

char **create_table_ord(char **table_buffer, char **table_result)
{
    int table_buffer_num = table_len(table_buffer);
    int v = 0;
    char **space_cut = my_split(table_buffer[0], " \t");
    char **space_cut_2 = my_split(table_buffer[1], " \t");

    if (table_buffer_num <= 2 && table_len(space_cut_2) == 1) {
        table_result = my_split(table_buffer[0], " \t");
        space_and_table_free(space_cut, space_cut_2, table_buffer);
        return table_result;
    }
    table_result = malloc(sizeof(char *)
    * (table_buffer_num + 1 + table_len(space_cut)));
    for (int i = 0; i < table_buffer_num; i++)
        add_value_table(table_buffer, &v, i, table_result);
    table_result[v] = NULL;
    space_and_table_free(space_cut, space_cut_2, table_buffer);
    return table_result;
}

int active_arrow_left(shell_a *info, char **table_words, char **cut_right_ar)
{
    char **get_val;
    int file_desc_2 = 0;
    char **new_table_words;

    if ((info->ar_left == 1 || info->ar_left == 4)
    && table_len(cut_right_ar) > 1) {
        get_val = my_split(cut_right_ar[1], " \t");
        file_desc_2 = open_file_or_error(info, O_RDONLY, cut_right_ar);
        if (file_desc_2 != -1)
            close(file_desc_2);
        new_table_words = create_new_table(table_words, get_val);
        display_results(info, new_table_words);
        table_free(get_val);
        free(new_table_words);
        return 0;
    }
    return 1;
}
