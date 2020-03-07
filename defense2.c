/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** defense2
*/

#include "include/my.h"

void defense_2(navy_t *navy, int pid, int line_attack, int col_attack)
{
    char col = col_attack + 'A';
    char line = line_attack + '1';
    int x = hit_or_miss(navy->map_usr, col_attack, line_attack);

    if (x == 2) {
        my_putchar(col);
        my_putchar(line);
        my_putstr(": ");
        my_putstr("hit\n\n");
        navy->map_usr[line_attack][col_attack] = 'x';
        navy->c_loose++;
        usleep(2000);
        kill(pid, SIGUSR1);
    }

}

void defense_3(navy_t *navy, int pid, int line_attack, int col_attack)
{
    int x = hit_or_miss(navy->map_usr, col_attack, line_attack);
    char col = col_attack + 'A';
    char line = line_attack + '1';

    if (x == 1) {
        my_putchar(col);
        my_putchar(line);
        my_putstr(": ");
        my_putstr("missed\n\n");
        navy->map_usr[line_attack][col_attack] = 'o';
        usleep(2000);
        kill(pid, SIGUSR2);
    }
}

int error_g(navy_t *navy)
{
    if (navy->type < 2 || navy->type > 5)
            return (84);
    if ((navy->x_b1 < 0 || navy->x_b1 > 8) ||
        (navy->y_b1 < -1 || navy->y_b1 > 7) ||
        (navy->x_b2 < 0 || navy->x_b2 > 8) ||
        (navy->y_b2 < -1 || navy->y_b2 > 7)) {
        return (84);
    }
    if ((navy->x_b1 + navy->y_b1) > (navy->x_b2 + navy->y_b2))
        return (84);
    if (verif_place(navy) != 0)
        return (84);
    return (0);
}