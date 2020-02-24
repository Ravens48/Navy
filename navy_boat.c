/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Placement des bateaux
*/

#include "include/my.h"
#include "get_next_line.h"

char **take_boat(navy_t *navy, char **map)
{
    char *save = NULL;
    save = get_next_line(navy->fd);

    for (;save != NULL;) {
        navy->type = (save[0] - '0');
        navy->x_b1 = save[2] - 'A';
        navy->y_b1 = (save[3] - '0') - 1;
        navy->x_b2 = save[5] - 'A';
        navy->y_b2 = (save[6] - '0') - 1;
        map = place_boat(navy, map);
        free(save);
        save = get_next_line(navy->fd);
    }
    close(navy->fd);
    return (map);
}

char **place_boat(navy_t *navy, char **map)
{
    if (navy->y_b1 == navy->y_b2) {
        while (navy->x_b1 <= navy->x_b2) {
            map[navy->y_b1][navy->x_b1] = navy->type + '0';
            navy->x_b1++;
        }
    }
    if (navy->x_b1 == navy->x_b2) {
        while (navy->y_b1 <= navy->y_b2) {
            map[navy->y_b1][navy->x_b1] = navy->type + '0';
            navy->y_b1++;
        }
    }
    return (map);
}