/*
** EPITECH PROJECT, 2020
** EPITECH
** File description:
** navy_player2
*/

#include "include/my.h"

int client_loop(navy_t *navy)
{
    global = 0;
    while (navy->c_win < 14) {
        my_putstr("waiting for enemy's attack...\n");
        defense(navy, navy->player_pid);
        attack_p1(navy->player_pid, navy);
        my_putstr("my positions:\n");
        print_my_map(navy->map_usr);
        my_putchar('\n');
        my_putstr("enemy's positions:\n");
        print_my_map(navy->map_ennemy);
        my_putchar('\n');
        printf("compteur de x : %d\n", navy->c_win);
    }
}
