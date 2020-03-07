/*
** EPITECH PROJECT, 2020
** EPITECH
** File description:
** decimal_to_binary
*/

#include "../../include/my.h"

char *decimal_to_binary(int n)
{
    int c;
    int d;
    int count = 0;
    char *pointer;

    pointer = (char *)malloc(8 + 1);

    if (pointer == NULL)
        return (NULL);
    for (c = 3; c >= 0; c--)
    {
        d = n >> c;
        if (d & 1)
            pointer[count] = 1 + '0';
        else
            pointer[count] = 0 + '0';
        count++;
    }
    pointer[count] = '\0';

    return  (pointer);
}