/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#ifndef MY_H_INCLUDE
    #define MY_H_INCLUDE
    #include <stdarg.h>
    #include <assert.h>
    #include <stdlib.h>
    #include <stdint.h>
    #include <signal.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "list.h"
    #include <dirent.h>
    #include <time.h>
    #include <limits.h>
    #include <errno.h>
    #include <grp.h>
    #include <pwd.h>
    #include <sys/wait.h>
    #define BLUE "\e[1;96m"
    #define WHITE "\e[0;00m"
//lib
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
void display_big_s(char *str_2);
void display_x(int maj, long long nbr);
void display_p(long long num);
int my_putoctal(unsigned int nb);
void display_o_hashtag(unsigned int arg);
int my_putstr(char const *str);
int my_check(char str);
char *my_strncat_custom(char *dest, char const *src, int nb, int nb2);
char **result2(int i, char const *str, int c, int o);
char **my_str_to_word_array(char const *str);
void my_putchar(char c);
char *my_itoa(int num);
long long my_atoi(char *str);
char *my_strcat(char *dest, char *src);
int my_intlen(int num);
int my_strcmp(char const *s1, char const *s2);
int check_match(char c, char *separator, int count);
int check_separator(char *str, char *separator, int v);
int count_sprt(char *str, char *separator, int col, char **cresult);
char **separate_table(char **result, char *str, char *separator, int count_st);
char **my_split(char *str, char *separator);
void start(va_list ap, int str_1, int forward_str_1, int indicator);
void start_next(va_list ap, int str_1, int forward_str_1, int indicator);
int re_indicator(char *str, int indicator);
int check_indicator(char *str, int *indicator, int *i, int *indicator_2);
int my_printf(char *str_1, ...);
int show_finish(int nb);
int my_put_nbr(int nb);
char *my_revstr(char *str);
int result_for_nbr(int var, int mult, char const *str);
int my_getnbr(char const *str);
unsigned int my_put_nbr_unsigned(unsigned int nb);
int display_big_str(int a, char *str_1, int i, int *indicator);
int params(int str_1, int forward_str_1);
void display_x_hashtag(int maj, unsigned int arg);
void display_d_plus(int arg);
char *gather_table(char **table, char c, int separator);
//minishell2
char ***create_table_semicolon(char *buffer);
int separator_mix(shell_a *info, char *buffer);
int error_exec_display_and_exeption(char **argv, shell_a *info);
int command_exec(char **argv, int err, shell_a *info);
int check_perm(char **words);
int condition_error_check(char *buff, char **words, shell_a *info);
size_t get_line(shell_a *info, size_t characters);
void condition_getline(char *buffer, shell_a *info);
off_t size_file(char const *file_path);
char *read_file(char *file);
int display_error_pmt(char *val, int num);
int err_not_fount_command(char **argv);
int error_no_directory(char *err);
int error_permission(char *err);
int error_directory(char *err);
int open_file_or_error(shell_a *info, int oflag, char **table_buffer);
int prosess_rdt_order(prss_t *pros, int check_odr, int oflag, shell_a *info);
void rdt_order(shell_a *info, char *buffer_gather);
void arrow_right_act(char **words, shell_a *info, char *buffer_gather);
void arrow_left_act(char **words, shell_a *info, char *buffer_gather);
void check_match_words(char **words, shell_a *info, int i, int *pass);
int end_unsetenv(char **buff, shell_a *info, int count);
int unset_env(char **words, shell_a *info);
void start_minishell_main(shell_a *info, char *buffer);
void sigint(int a);
void add_envp_table(char **envp, shell_a *info);
int start_minishell(char **envp);
void detect_first_rdt(char **words, int detect, shell_a *info, char *buffer);
int detect_first_arrow(char *buffer_gather);
void my_free_tab(char **tab);
int my_strcmp_custom(char const *s1, char const *s2);
int check_space(char *buffer);
int env_arg_exists(char **envp, char *search);
int table_len(char **string);
int check_order(char **words, shell_a *info);
int get_pwd(shell_a *info, char **words);
void set_env_add(char **words, char **resp, int i);
void set_env(shell_a *info, char **words, int count_mal);
void display_results(shell_a *info, char **words);
void table_free(char **table);
int count_value(char *buffer, char c);
int count_dubble_value(char *buffer, char c);
int count_only_solo_c(char *buffer, char c);
void *utils_loop(int fd[], pid_t *pid);
int cd_error(char **words);
int get_env_nbr(char **envp, char *src);
int cd_with_err(char **words, shell_a *info);
char *get_env(char **envp, char *resp, char *src);
void display_env(shell_a *info);
int err_env(char **argv);
int exception_exec(char **argv, shell_a *info);
int display_erros_arrows(int err, shell_a *info);
int check_long(char *buff);
int check_directory(char *file);
int check_val_home(char **words, char *buff, shell_a *info);
int set_env_check_error(char **words);
int set_env_check(char **words, shell_a *info, int count_mal);
char *remove_quotation_mark(char *buffer);
int check_more(char *buffer, char c);
int check_arrows(char *buffer, char c, char letter, int count_table);
int check_arrow(char *buffer, char c, int res);
char *check_arrow_main(char **words, int *ar_right, int *ar_left);
void active_arrow_order(char **words, shell_a *info, char *buffer);
char env_raplace_add_value(char **words, char **resp, int i, shell_a *info);
void replace_env(char **words, shell_a *info);
int exit_or_print_exit(char **words, shell_a *info);
int main(int argc, char **argv, char **envp);
void get_dup2(char ***order, int fd[]);
int pipe_line(char ***order, shell_a *info, int status);
void pipe_free(char ***split_s, char **split_p, char *table_m, char **words);
void pipe_check(char **words, shell_a *info, char *buffer);
int active_arrow_left(shell_a *info, char **table_words, char **cut_right_ar);
char **create_table_ord(char **table_buffer, char **table_result);
char **create_new_table(char **table_words, char **get_val);
int prosess_file_inject(prss_t *pros, int check_odr, int oflag, shell_a *info);
void rdt_file_inject(shell_a *info, char *buffer_gather, int oflag);
int choise_file_add_move(shell_a *info, char **get_val, int file_desc_2);
int active_arrow_right(shell_a *info, char **table_words, char **cut_right_ar);
int redirection_glue(char *buffer, char c);
int redirection_glue_no_space(char *buffer);
int check_valide_order(char ***split_space, shell_a *info);
char *my_pwd(void);
int check_semicolon(char *buffer);
char *get_exec_cmd(char *cmd, shell_a *info);
int status_update(int status, shell_a *info);
void parse_redirection(char **order, shell_a *info);
int count_loop_values(char *c, int i, char letter);
int count_values(char *buffer, char *c);
int get_redirection(char *buff, int nbr);
int count_rdr_split(char *buff);
int free_dubble_buff(char *buff, char *path_buff);
int set_env_check_error_next(char **words);
int set_env_check_error(char **words);
int set_env_check(char **words, shell_a *info, int count_mal);
int found_dollar(char *split_space);
int split_table_dollar_tb(char **split_dollar,char **res, int i, char *status);
char *split_table_dollar(char *split_space, char *status, char *res_st, int i);
int loop_dollar(char **split_space, char **table_res, int i, char *status);
char *dollar_insert(char *buffer, char *status);
int check_pipe_next(char *table_merge, int pass);
int check_pipe(char **table_buffer);
int check_and_next(int pass, char *table_merge);
int check_and(char **table_buffer);
int check_and_pipe(char **table_buffer);
char **result_table_loop(char **table, int count_dubble_pipe, char *buffer);
char **table_pipe(char *buffer);
char ***create_table_pipe(char *buffer);
char ***create_table_semicolon_and_and(char *buffer, char *c);
int count_len(int i, char *buffer);

#endif
