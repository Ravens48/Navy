/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Gestion des erreurs de MAP
*/

#include "include/my.h"
#include "get_next_line.h"

int type_boat(navy_t *navy)
{
    char *verif_type = NULL;
    verif_type = get_next_line(navy->fd);
    navy->c_boat = 0;

    for (; verif_type != NULL;) {
        navy->type = (verif_type[0] - '0');
        navy->x_b1 = verif_type[2] - 'A';
        navy->y_b1 = (verif_type[3] - '0') - 1;
        navy->x_b2 = verif_type[5] - 'A';
        navy->y_b2 = (verif_type[6] - '0') - 1;
        if (navy->type < 2 || navy->type > 5)
            return (84);
        if ((navy->x_b1 < 0 || navy->x_b1 > 8) ||
            (navy->y_b1 < -1 || navy->y_b1 > 7) ||
            (navy->x_b2 < 0 || navy->x_b2 > 8) ||
            (navy->y_b2 < -1 || navy->y_b2 > 7)) {
            return (84);
        }
        if (verif_place(navy) != 0)
            return (84);
        navy->boat_count += verif_type[0];
        free(verif_type);
        verif_type = get_next_line(navy->fd);
        navy->c_boat++;
    }
    if (navy->boat_count != 206)
        return (84);
    close(navy->fd);
    return (0);
}

int verif_place(navy_t *navy)
{
    char **map = navy->map_usr;

    if (navy->y_b1 == navy->y_b2) {
        while (navy->x_b1 <= navy->x_b2) {
            if (map[navy->y_b1][navy->x_b1] != '.')
                return (84);
            map[navy->y_b1][navy->x_b1] = navy->type + '0';
            navy->x_b1++;
        }
    }
    if (navy->x_b1 == navy->x_b2) {
        while (navy->y_b1 <= navy->y_b2) {
            if (map[navy->y_b1][navy->x_b1] != '.')
                return (84);
            map[navy->y_b1][navy->x_b1] = navy->type + '0';
            navy->y_b1++;
        }
    }
    return (0);
}

int error_gesture(navy_t *navy)
{
    if (type_boat(navy) == 84)
        return (84);
    if (navy->c_boat < 4 || navy->c_boat > 4) {
        my_putstr_error("Vous devez placez 4 bateau\n");
        return (84);
    }
    return (0);
}