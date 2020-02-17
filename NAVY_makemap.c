/*
** EPITECH PROJECT, 2020
** NAVY
** File description:
** makemap
*/

#include "include/my.h"

char **first_line(int i, char **map)
{
    if (i == 0)
        map[i] = " |A B C D E F G H";
    if (i == 1)
        map[i] = "-+---------------";
    return (map);
}

char **column(int i, int x, int add, char **map)
{   
    if (x == 0 && i > 1)
        map[i][x] = '1' + add;
    if (x == 1 && i > 1)
        map[i][x] = '|';
    if (x > 1 && i > 1) {
        if (x % 2 == 0)
            map[i][x] = '.';
            else
                map[i][x] = ' ';
        }
    return (map);
}

void set_map(char **map, int size, int col_len)
{
    int add = -2;
    int i;
    int x;

    for (i = 0; i != size; i++, add++) {
        for (x = 0; x != col_len; x++) {
            map = first_line(i, map);
            map = column(i, x, add, map);
        }
    }
}

char **create_map(int size)
{
    int i;
    int col_len = 17;
    int size_map = size;
    char **map = malloc(sizeof(char *) * size_map);

    for (i = 0; i <= size_map; i++) {
        map[i] = malloc(sizeof(char) * col_len);
    }
    set_map(map, size_map, col_len);
    return (map);
}

void print_my_map(void)
{
    my_putstr("my positions:\n");
    int size = 10;
    char **map = create_map(size);
    for (int i = 0; i < size + 1; i++) {
       my_putstr(map[i]);
       my_putchar('\n');
    }
}
