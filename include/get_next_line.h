/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** get_next_line
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef READ_SIZE
#define READ_SIZE (8)

char *get_next_line(const int fd);
int my_putstr(char const *str);
char *my_realloc(char *buff, int size);
char *my_line(char *buff, int *nbchar, int last);

#endif /* !GET_NEXT_LINE_H_ */