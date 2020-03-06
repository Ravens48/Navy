/*
** EPITECH PROJECT, 2020
** EPITECH
** File description:
** navy_player1
*/

#include "include/my.h"

int server_loop(navy_t *navy)
{
    while (navy->c_win < 14) {
        attack_p1(navy->other_pid, navy);
        my_putstr("waiting for enemy's attack...\n");
        defense(navy, navy->other_pid);
        my_putstr("my positions:\n");
        print_my_map(navy->map_usr);
        my_putchar('\n');
        my_putstr("enemy's positions:\n");
        print_my_map(navy->map_ennemy);
        my_putchar('\n');
        printf("compteur de x : %d\n", navy->c_win);
    }
}

void receive_hit_or_miss(int col, int line, navy_t *navy)
{
    pause();
    usleep(2000);
    char cols = col + 'A';
    char lines = line + '1';
    if (global == '0') {
        my_putchar(cols);
        my_putchar(lines);
        navy->c_win++;
        navy->map_ennemy[line][col] = 'x';
        my_putstr(": ");
        my_putstr("hit\n\n");
    }
    if (global == '1'){
        my_putchar(cols);
        my_putchar(lines);
        navy->map_ennemy[line][col] = 'o';
        my_putstr(": ");
        my_putstr("missed\n\n");
    }
}