/*
** EPITECH PROJECT, 2018
** task02
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));

    return (0);
}