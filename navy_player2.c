/*
** EPITECH PROJECT, 2020
** EPITECH
** File description:
** navy_player2
*/

#include "include/my.h"

void client_loop(navy_t *navy)
{
    global = 0;
    while (1) {
        my_putstr("waiting for enemy's attack...\n");
        defense(navy, navy->player_pid);
        attack_p1(navy->player_pid, navy);
        print_my_map(navy->map_usr);
        my_putchar('\n');
        my_putstr("Enemy's positions:\n");
        print_my_map(navy->map_ennemy);
        my_putchar('\n');
    }
}
