/*
** EPITECH PROJECT, 2020
** EPITECH
** File description:
** navy_game_loop
*/

#include "include/my.h"

int attack_p1(int pid)
{
    int col = -1;
    int line = -1;
    char *bn_col;
    char *bn_line;
    int x;
    size_t buffer_size = 0;

    do {
        char *buffer = NULL;
        my_putstr("attack: ");
        x = getline(&buffer, &buffer_size, stdin);
        if (x == -1) {
            return (-1);
        }
        col = (buffer[0]) - 'A';
        line = my_getnbr(&buffer[1]) - 1;
    } while ((col < 0 || col > 8) && (line < 0 || line > 8));
    bn_col = decimal_to_binary(col);
    bn_line = decimal_to_binary(line);
    details_choice(bn_col, pid);
    details_choice(bn_line, pid);
    return (0);
}

void details_choice(char *choice, int pid)
{
    for (int i = 0; choice[i] != '\0'; i++) {
        if (choice[i] == '0') {
            usleep(2000);
            kill(pid, SIGUSR1);
        }
        if (choice[i] == '1') {
            usleep(2000);
            kill(pid, SIGUSR2);
        }
        pause();
    }
}

void recup_attact_details(navy_t *navy, int pid)
{
    int i = 0;
    int tour = 0;

    while (i < 4 && tour < 2) {
        pause();
        usleep(2000);
        if (tour == 0)
            navy->col_details[i] = global;
        if (tour == 1)
            navy->line_details[i] = global;
        i++;
        if (i == 4) {
            i = 0;
            tour++;
        }
        kill(pid, SIGUSR1);
    }
    navy->col_details[4] = '\0';
    navy->line_details[4] = '\0';
}

int defense(navy_t *navy, int pid)
{
    int x = 0;
    recup_attact_details(navy, pid);
    int col_attack = binary_to_decimal(navy->col_details);
    int line_attack = binary_to_decimal(navy->line_details);
    x = hit_or_miss(navy->map_ennemy, col_attack, line_attack);

    if (x == 2) {
        my_putstr("normalement on touche\n");
    }
    if (x == 1) {
        my_putstr("normalement on touche pas\n");
    }
    return (0);
}
