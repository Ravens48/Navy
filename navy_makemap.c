/*
** EPITECH PROJECT, 2020
** NAVY
** File description:
** makemap
*/

#include "include/my.h"

char **create_map(int nb_line, int nb_colonne)
{
    int j = 0;
    int y = 0;
    int i = 0;
    char **map = malloc(sizeof(char *) * (nb_line + 1));

    for (; i < nb_line; i++) {
        map[i] = malloc(sizeof(char) * (nb_colonne + 1));
        for (y = 0; y < nb_colonne; y++, j++) {
                map[i][y] = '.';
        }
        j = 0;
        map[i][y] = '\0';
    }
    map[i] = NULL;
    return (map);
}

char **print_my_map(char **map)
{
    int x = 1;
    int i = 0;
    int j = 0;

    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (; map[i] != NULL; i++, x++) {
        my_put_nbr(x);
        my_putchar('|');
        for (; map[i][j] != '\0'; j++){
            my_putchar(map[i][j]);
            my_putchar(' ');
        }
        j = 0;
        my_putchar('\n');
    }
    return (map);
}