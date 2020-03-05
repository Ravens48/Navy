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
        defense(navy, navy->player_pid);
        attack_p1(navy->player_pid);
    }
}
