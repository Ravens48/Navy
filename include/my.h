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
#include <time.h>

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
    char col_details[5];
    char line_details[5];
    int other_pid;
    int player_pid;
    int c_win;
    int c_loose;
    int boat_count;
    struct sigaction sig;
} navy_t;

extern int global;

void my_putchar(char c);
int my_strlen(char const *str);
int my_putstr_error(char const *str);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_getnbr(char const *str);
void connect(int ac, char **av, navy_t *navy);
void help(void);
void print_player(int ac, char **av, navy_t *navy);
char **create_map(int nb_line, int nb_colonne);
void set_map(char **map, int size, int col_len);
char **column(int i, int x, int add, char **map);
char **first_line(int i, char **map);
int my_put_nbr(int n);
char *open_file(char *str);
char **str_to_word_array(char *str);
int count_word(const char *str);
char *decimal_to_binary(int n);
void *my_memset(void *str, int value, int len);
char **place_boat(navy_t *navy, char **map);
char **take_boat(navy_t *navy, char **map);
int error_gesture (navy_t *navy);
int type_boat(navy_t *navy);
int verif_place(navy_t *navy);
int defense(navy_t *navy, int pid);
void player_1_turn(navy_t *navy);
void player_2_turn(navy_t *navy);
int binary_to_decimal(char *binary);
navy_t *malloc_s(void);
void initialise_map(navy_t *navy);
int helper(int ac, char **av);
int game_main_2(int ac, char **av, navy_t *navy, int j);
int defense(navy_t *navy, int pid);
void defense_2(navy_t *navy, int pid, int line_attack, int col_attack);
void defense_3(navy_t *navy, int pid, int line_attack, int col_attack);

int error_g(navy_t *navy);
void error(int col, int line);
void signal_send(int pid, int signal);
int hit_or_miss(char **map, int col, int line);
char **print_my_map(char **map);

int attack_p1(int pid, navy_t *navy);
void recup_attact_details(navy_t *navy, int pid);
int server_loop(navy_t *navy);
int client_loop(navy_t *navy);
int engame(navy_t *navy);
void details_choice(char *choice, int pid);
int nanosleep(const struct timespec *req, struct timespec *rem);
void receive_hit_or_miss(int col, int line, navy_t *navy);
int game_main (int ac, char **av, navy_t *navy);

#endif /* !MY_H_ */
