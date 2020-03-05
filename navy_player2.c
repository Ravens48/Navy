/*
** EPITECH PROJECT, 2020
** EPITECH
** File description:
** navy_player2
*/

#include "include/my.h"

void client_loop(navy_t *navy, int pid, int signal_1, int signal_2)
{
    global = 0;
    while (1) {
    
    //pause();
    defense(navy, navy->player_pid, SIGUSR1, SIGUSR2);
    // usleep(2000);
    // kill(navy->player_pid, SIGUSR2);
    attack_p1(navy, navy->player_pid, SIGUSR1, SIGUSR2);
    }
}
