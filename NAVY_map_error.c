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
    //printf("coucou");
    char *verif_type = NULL;
    verif_type = get_next_line(navy->fd);

    for (; verif_type != NULL;) {
        navy->type = (verif_type[0] - '0');
        if (navy->type < 2 || navy->type > 5) {
            return (84);
        }
        free(verif_type);
        verif_type = get_next_line(navy->fd);
    }
    close (navy->fd);
    return (0);
}

int error_gesture(navy_t *navy) 
{
    if (type_boat(navy) == 84) {
        my_putstr_error("La map est invalide les bateaux "); 
        my_putstr_error("doivent etre compris entre 2 et 5\n");
        return (84);
    }
    return (0);
}