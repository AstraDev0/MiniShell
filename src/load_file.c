/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-42sh-maxime.gregoire
** File description:
** load_file.c
*/

#include "my.h"

off_t size_file(char const *file_path)
{
    off_t size;
    struct stat buf;

    if (stat(file_path, &buf) == -1)
        return (-1);
    return buf.st_size;
}

char *read_file(char *file)
{
    int file_fd = open(file, O_RDONLY);
    off_t file_size = size_file(file);
    char *map_file;

    if (file_fd == -1 || file_size == -1)
        return (NULL);
    map_file = malloc(sizeof(char) * (file_size + 1));
    if (!map_file || read(file_fd, map_file, file_size) == -1)
        return (NULL);
    map_file[file_size] = '\0';
    close(file_fd);
    return map_file;
}
