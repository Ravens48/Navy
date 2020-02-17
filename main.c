/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** main
*/

#include "include/my.h"

int main(int ac, char **av)
{
    if (ac == 1)
        return (84);
    if (ac == 2) {
        help(av);
    }
    return (0);
}