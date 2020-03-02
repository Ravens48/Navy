/*
** EPITECH PROJECT, 2020
** EPITECH
** File description:
** navy_hit_or_miss
*/

int hit_or_miss(char **map, int col, int line)
{
    if (map[col][line] != '.')
        return (2);
    if (map[col][line] == '.')
        return (1);
    if (map[col][line] == 'o' || map[col][line] == 'x')
        return (0);
}
