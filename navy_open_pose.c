/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Gestion des positions
*/

#include "include/my.h"

char *open_file(char *str)
{
    struct stat f_len;
    int size;

    stat(str, &f_len);
    size = f_len.st_size;
    char *buffer = malloc(sizeof(char) * size + 1);
    int fd;

    fd = open(str, O_RDONLY);
    if (fd == -1) {
        return (NULL);
    }
    read(fd, buffer, size);
    close(fd);
    buffer[size] = 0;
    return (buffer);
}
