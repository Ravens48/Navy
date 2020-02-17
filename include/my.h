/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef MY_H_
#define MY_H_

typedef struct navy_s {
    char **map_usr1;
    char **map_ennemy2;
    char **map_usr2;
    char **map_ennemy1;
}navy_t;

void my_putchar(char c);
int my_strlen(char const *str);
int my_putstr_error(char const *str);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int help(char **av);
void print_my_map(void);
char **create_map(int size);
void set_map(char **map, int size, int col_len);
char **column(int i, int x, int add, char **map);
char **first_line(int i, char **map);

#endif /* !MY_H_ */
