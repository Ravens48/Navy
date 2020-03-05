/*
** EPITECH PROJECT, 2020
** EPITECH
** File description:
** navy_player1
*/

#include "include/my.h"

void server_loop(navy_t *navy, int pid, int signal_1, int signal_2)
{
    while (1) {
        // usleep(2000);
        // kill(navy->other_pid, SIGUSR1);
        attack_p1(navy, navy->other_pid, SIGUSR1, SIGUSR2);
        printf("on passe dans la loop attack du server\n");
     
     //   pause();
        defense(navy, navy->other_pid, SIGUSR1, SIGUSR2);
        // usleep(2000);
        // kill(navy->other_pid, SIGUSR1);
    }

}