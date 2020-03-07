/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** help
*/

#include "include/my.h"

void help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfirst_player_pid: only for the 2nd player.");
    my_putstr(" pid of the first player\n");
    my_putstr("\tnavy_position: file representing the ");
    my_putstr("positions of the ships.\n");
}

int helper(int ac, char **av)
{
    if ((ac == 2) && (my_strcmp(av[1], "-h") == 0)) {
        help();
        return (0);
    }
    return (1);
}

int game_main_2(int ac, char **av, navy_t *navy, int j)
{
    if (ac == 3) {
        print_player(ac, av, navy);
        j = client_loop(navy);
        if (j == 1) {
            print_my_map(navy->map_usr);
            my_putchar('\n');
            print_my_map(navy->map_ennemy);
            my_putstr("\nI won\n");
            return (0);
        }
        if (j == 2) {
            print_my_map(navy->map_usr);
            my_putchar('\n');
            print_my_map(navy->map_ennemy);
            my_putstr("\nEnemy won\n");
            return (1);
        }
    }
    return (0);
}