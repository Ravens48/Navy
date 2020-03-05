/*
** EPITECH PROJECT, 2020
** EPITECH
** File description:
** navy_player1
*/

#include "include/my.h"

void server_loop(navy_t *navy)
{
    while (1) {
        attack_p1(navy->other_pid);
        defense(navy, navy->other_pid);
    }
}