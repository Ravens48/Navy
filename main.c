/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** main
*/

#include "include/my.h"

navy_t *malloc_s(void)
{
    navy_t *navy = malloc(sizeof(navy_t));
    
    if (!navy)
        return (NULL);
    navy->map_usr1 = NULL;
    return (navy);
}

int main(int ac, char **av)
{
    navy_t *navy = NULL;
    //if (ac == 1)
    //    return (84);
    if (ac == 2) {
        help(av);
    }
    else {
        print_my_map();
    }
    return (0);
}