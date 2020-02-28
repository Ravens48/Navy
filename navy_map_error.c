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
    char **map = navy->map_usr;
    verif_type = get_next_line(navy->fd);
    navy->c_boat = 0;

    for (; verif_type != NULL;) {
        navy->type = (verif_type[0] - '0');
        navy->x_b1 = verif_type[2] - 'A';
        navy->y_b1 = (verif_type[3] - '0') - 1;
        navy->x_b2 = verif_type[5] - 'A';
        navy->y_b2 = (verif_type[6] - '0') - 1;
        //si il n y a pas assez de bateau
        if (navy->type < 2 || navy->type > 5) {
            my_putstr_error("Attention, les bateau ont une taille de 2 mininum et 5 maximum\n");
            return (84);
        }
        //si les coordonee sont trop grande pour la carte
        if ((navy->x_b1 < 0 || navy->x_b1 > 8) ||
                (navy->y_b1 < -1 || navy->y_b1 > 7) ||
                (navy->x_b2 < 0 || navy->x_b2 > 8) ||
                (navy->y_b2 < -1 || navy->y_b2 > 7)){
                my_putstr_error("Attention, un ou plusieurs bateau se trouve en dehors de la carte\n");
                return (84);
            }
        //si la coordonee 1 et 2 sont inverse
        if ((navy->x_b1 + navy->y_b1) > (navy->x_b2 + navy->y_b2))
            return (84);
        //si il y a plusieurs fois le meme types de bateau ?
        //eviter la superposition de bateau ??
        if ((map = verif_place(navy)) != 0) {
            my_putstr_error("Attention, les bateaux se superpose\n");
            return (84);
        }
        free(verif_type);
        verif_type = get_next_line(navy->fd);
        navy->c_boat++;
    }
    close (navy->fd);
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
        my_putstr_error("Vous devez placez 4 bateau");
        return (84);
    }
    return (0);
}