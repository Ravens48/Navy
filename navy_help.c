/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** help
*/

#include "include/my.h"

int help(char **av)
{
    if (my_strcmp(av[1], "-h")) {
        my_putstr("USAGE\n");
        my_putstr("\t./navy [first_player_pid] navy_positions\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("\tfirst_player_pid: only for the 2nd player.");
        my_putstr(" pid of the first player\n");
        my_putstr("\tnavy_position: file representing the ");
        my_putstr("positions of the ships.\n");
    }
    return (0);
}