/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_putchar_error
*/

#include "../../include/my.h"

int my_putstr_error(char const *str)
{
    write(2, str, my_strlen(str));

    return (0);
}