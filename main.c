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
    navy->map_usr = NULL;
    navy->map_ennemy = NULL;
    return (navy);
}

void initialise_map(navy_t *navy) 
{
    navy->map_usr = create_map();
    navy->map_ennemy = create_map();
}

int main(int ac, char **av)
{
    navy_t *navy = malloc_s();
    initialise_map(navy);
    char **map_boat = NULL;
    navy->fd = open(av[1], O_RDONLY);
    if (ac == 2) {
        help(av);
    }
    if (error_gesture(navy) == 84)
        return (84);
    navy->fd = open(av[1], O_RDONLY);
    my_putstr("my positions:\n");
    map_boat = take_boat(navy, navy->map_usr);
    print_my_map(map_boat);
    my_putchar('\n');
    my_putstr("Enemy's positions:\n");
    print_my_map(navy->map_ennemy);
    return (0);
}