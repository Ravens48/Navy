/*
** EPITECH PROJECT, 2019
** my_memset.c
** File description:
** my_memset
*/

#include "../../include/my.h"

void *my_memset(void *str, int value, int len)
{
    int i = 0;
    char *s = str;

    for (; i < len; i++) {
        s[i] = value;
    }
    return (str);
}
