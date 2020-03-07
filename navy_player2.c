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
    while (1) {
        my_putstr("waiting for enemy's attack...\n");
        defense(navy, navy->player_pid);
        if (navy->c_loose == 14) {
            break;
        }
        attack_p1(navy->player_pid, navy);
        if (navy->c_win == 14)
            break;
        my_putstr("my positions:\n");
        print_my_map(navy->map_usr);
        my_putchar('\n');
        my_putstr("enemy's positions:\n");
        print_my_map(navy->map_ennemy); my_putchar('\n');
    }
    if (navy->c_loose == 14)
        return (2);
    if (navy->c_win == 14)
        return (1);
    return (0);
}
