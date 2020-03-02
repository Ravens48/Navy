/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef MY_H_
#define MY_H_

typedef struct navy_s {
    char **map_usr;
    char **map_ennemy;
    int fd;
    int type;
    int x_b1;
    int y_b1;
    int x_b2;
    int y_b2;
    int c_boat;
}navy_t;

typedef struct connect_s
{
    int other_pid;
    int signal_nb;
}connect_t;

connect_t co_term;

void my_putchar(char c);
int my_strlen(char const *str);
int my_putstr_error(char const *str);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_getnbr(char const *str);
void connect(int ac, char **av);
int help(char **av);
char **print_my_map(char **map);
char **create_map(int nb_line, int nb_colonne);
void set_map(char **map, int size, int col_len);
char **column(int i, int x, int add, char **map);
char **first_line(int i, char **map);
int my_put_nbr(int n);
char *open_file(char *str);
char **str_to_word_array(char *str);
int count_word(const char *str);
char *decimal_to_binary(int n);
int binary_to_decimal(char *binary);
void *my_memset(void *str, int value, int len);
char **place_boat(navy_t *navy, char **map);
char **take_boat(navy_t *navy, char **map);
int error_gesture (navy_t *navy);
int type_boat(navy_t *navy);
int verif_place(navy_t *navy);

#endif /* !MY_H_ */
