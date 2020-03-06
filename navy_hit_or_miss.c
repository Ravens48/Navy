/*
** EPITECH PROJECT, 2020
** EPITECH
** File description:
** navy_hit_or_miss
*/

#include "include/my.h"

int hit_or_miss(char **map, int col, int line)
{
    if (map[line][col ] != '.') {
        return (2);
    }
    if (map[line][col] == '.') {
        return (1);
    }
    return (0);
}
