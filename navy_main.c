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
    navy->map_usr = create_map(8, 8);
    navy->map_ennemy = create_map(8, 8);
}

void print_player(int ac, char **av, navy_t *navy)
{
    navy->fd = open(av[ac - 1], O_RDONLY);
    my_putstr("my positions:\n");
    navy->map_usr = take_boat(navy, navy->map_usr);
    print_my_map(navy->map_usr);
    my_putchar('\n');
    my_putstr("enemy's positions:\n");
    print_my_map(navy->map_ennemy);
    my_putchar('\n');
}

int helper(int ac, char **av)
{
    if ((ac == 2) && (my_strcmp(av[1], "-h") == 0)) {
        help();
        return (0);
    }
    return (1);
}

int main(int ac, char **av)
{
    navy_t *navy = malloc_s();

    initialise_map(navy);
    if (helper(ac, av) == 0)
        return (0);
    if (ac == 2)
        navy->fd = open(av[1], O_RDONLY);
    if (ac == 3)
        navy->fd = open(av[2], O_RDONLY);
    if (error_gesture(navy) == 84)
        return (84);
    connect(ac, av, navy);
    if (ac == 2) {
        print_player(ac, av, navy);
        server_loop(navy);
    }
    if (ac == 3) {
        print_player(ac, av, navy);
        client_loop(navy);
    }
    return (0);
}