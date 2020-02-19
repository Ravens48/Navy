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
    navy->map_usr2 = NULL;
    navy->map_ennemy1 = NULL;
    navy->map_ennemy2 = NULL;
    return (navy);
}

void initialise_map(navy_t *navy) {
    navy->map_usr1 = create_map();
    navy->map_usr2 = create_map();
    navy->map_ennemy1 = create_map();
    navy->map_ennemy2 = create_map();
}

int main(int ac, char **av)
{
    navy_t *navy = malloc_s();
    initialise_map(navy);
    char *position;
    //if (ac == 2) {
    //    help(av);
    //}
        position = open_file(av[1]);
        printf("%s\n", position);
        print_my_map(navy->map_usr1);
        print_enemy_map(navy->map_usr2);
    
    return (0);
}