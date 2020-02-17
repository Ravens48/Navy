/*
** EPITECH PROJECT, 2020
** NAVY
** File description:
** makemap
*/

#include "include/my.h"

char **create_map(void)
{
    int nb_line = 10;
    int nb_colonne = 16;
    int j = 0;
    int y = 0;
    int i = 0;
    char **map = malloc(sizeof(char *) * (nb_line + 1));

    for (; i < nb_line; i++) {
        map[i] = malloc(sizeof(char) * (nb_colonne + 1));
        for (y = 0; y < nb_colonne; y++, j++) {
            if (j % 2 == 0)
                map[i][y] = '.';
            else
                map[i][y] = ' ';
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
    int size = 8;
    static int i = 0;

    my_putstr("my positions:\n");
    printf(" |A B C D E F G H\n");
    printf("-+---------------\n");
    for (; i < size; i++, x++) {
        my_put_nbr(x);
        my_putchar('|');
        my_putstr(map[i]);
        my_putchar('\n');
    }
    return (map);
}

char **print_enemy_map(char **map)
{
    int x = 1; 
    int size = 8;
    static int i = 0;

    my_putchar('\n');
    my_putstr("enemy's positions:\n");
    printf(" |A B C D E F G H\n");
    printf("-+---------------\n");
    for (; i < size; i++, x++) {
        my_put_nbr(x);
        my_putchar('|');
        my_putstr(map[i]);
        my_putchar('\n');
    }
    return (map);
}