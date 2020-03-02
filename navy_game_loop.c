/*
** EPITECH PROJECT, 2020
** EPITECH
** File description:
** navy_game_loop
*/

#include "include/my.h"

char game_loop_p1(char **map)
{
    int col = 0;
    int line = 0;
    int x = 0;
    size_t buffer_size = 32;
    char *buffer = malloc(sizeof(char) * buffer_size + 1);
    
    my_putstr("Attack: ");
    x = getline(&buffer, &buffer_size, stdin);
    if (x == -1)
        return (-1);
    col = (buffer[0] - 'A');
    line = my_getnbr(buffer[1]);
    // envoie des signaux
    //utliisation du int to binary
}

char game_loop_p2(char **map)
{
    int col = 0;
    int line = 0;
    int x = 0;
    char *buffer;
    size_t buffer_size = 32;

    buffer = malloc(sizeof(char) * buffer_size + 1);
    my_putstr("Attack: ");
    x = getline(&buffer, &buffer_size, stdin);
    if (x == -1)
        return (-1);
    col = (buffer[0] - 'A');
    line = my_getnbr(buffer[1]);
    // envoie des signaux
    //utliisation du int to binary
}