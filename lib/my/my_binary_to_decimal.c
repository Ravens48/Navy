/*
** EPITECH PROJECT, 2020
** EPITECH
** File description:
** my_binary_to_decimal
*/

#include "../../include/my.h"

int binary_to_decimal(char *binary)
{
    int res = 0;
    int mul = 1;
    if (binary == NULL)
        return (-1);
    int i = my_strlen(binary) - 1;

    for (; binary[i]; i--) {
        if (binary[i] == '1')
            res += mul;
        mul *= 2;
    }
    return (res);
}