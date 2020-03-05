/*
** EPITECH PROJECT, 2020
** EPITECH
** File description:
** navy_hit_or_miss
*/

#include "include/my.h"

int hit_or_miss(char **map, int col, int line)
{
    if (map[col][line] != '.') {
        return (2);
    }
    if (map[col][line] == '.') {
        //my_putstr("MISS");
        return (1);
    }
    return (0);
}
