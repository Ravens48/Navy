/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (i = 0; s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return (-1);
        }
    }
    return (0);
}