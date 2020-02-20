/*
** EPITECH PROJECT, 2020
** connection
** File description:
** navy
*/

#include "include/my.h"

void wait(int sig, siginfo_t *sign)
{
    if (sig == SIGUSR1) {
        co_term.other_pid = sign->si_pid;
        usleep(1000);
        kill(co_term.other_pid, SIGUSR1);
    }
}

void confirm(int sig, siginfo_t *sign)
{
    if (sig == SIGUSR1)
        usleep(1000);
}

void player(int id_process)
{
    struct sigaction sig;

    sig.sa_sigaction = wait;
    sigemptyset(&sig.sa_mask);
    sig.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sig, NULL);
    my_putstr("my_pid: ");
    my_put_nbr(id_process);
    my_putchar('\n');
    my_putstr("waiting for ennemy connection...\n\n");
    pause();
    my_putstr("ennemy connected\n\n");
}

void enemy_player(int id_process, char **av)
{
    int player = my_getnbr(av[1]);
    struct sigaction sig_2;

    sig_2.sa_sigaction = confirm;
    sigemptyset(&sig_2.sa_mask);
    sig_2.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sig_2, NULL);
    my_putstr("my_pid: ");
    my_put_nbr(id_process);
    my_putchar('\n');
    usleep(1000);
    kill(player, SIGUSR1);
    pause();
    my_putstr("succesfully connected\n\n");
}

void connect(int ac, char **av)
{
    int id_process = getpid();

    if (ac == 2)
        player(id_process);
    else if (ac == 3)
        enemy_player(id_process, av);
}