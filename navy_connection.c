/*
** EPITECH PROJECT, 2020
** connection
** File description:
** navy
*/

#include "include/my.h"

int global = -1;

void handler(int sig, siginfo_t *sign, void *context)
{
    (void)context;

    if (global == -1) {
        global = sign->si_pid;
        return;
    }
    if (sig == SIGUSR1) {
        global = '0';
    }
    if (sig == SIGUSR2) {
        global = '1';
    }
}

void player(navy_t *navy, int id_process)
{
    navy->sig.sa_sigaction = handler;

    sigemptyset(&navy->sig.sa_mask);
    navy->sig.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &navy->sig, NULL);
    sigaction(SIGUSR2, &navy->sig, NULL);
    my_putstr("my_pid: ");
    my_put_nbr(id_process);
    my_putchar('\n');
    my_putstr("waiting for ennemy connection...\n\n");
    pause();
    usleep(2000);
    navy->other_pid = global;
    kill(navy->other_pid, SIGUSR1);
    my_putstr("enemy connected\n\n");
}

void enemy_player(int id_process, char **av, navy_t *navy)
{
    navy->player_pid = my_getnbr(av[1]);
    navy->sig.sa_sigaction = handler;

    sigemptyset(&navy->sig.sa_mask);
    navy->sig.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &navy->sig, NULL);
    sigaction(SIGUSR2, &navy->sig, NULL);
    my_putstr("my_pid: ");
    my_put_nbr(id_process);
    my_putchar('\n');
    kill(navy->player_pid, SIGUSR1);
    pause();
    my_putstr("succesfully connected\n\n");
}

void connect(int ac, char **av, navy_t *navy)
{
    int id_process = getpid();

    if (ac == 2) {
        player(navy, id_process);
    }
    else if (ac == 3) {
        enemy_player(id_process, av, navy);
    }
}