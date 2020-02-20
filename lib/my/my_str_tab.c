/*
** EPITECH PROJECT, 2020
** TEK_1_2019
** File description:
** my_str_tab
*/

#include "../../include/my.h"

int count_word(const char *str)
{
    int c_word = 0;
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] == '\n' && str[i + 1] != '\n')
            c_word++;
        }
    if (i != 0)
        c_word += 1;
    return (c_word);
}

char **str_to_word_array(char *str)
{
    int nb_word = count_word(str);
    char **tab_array = malloc(sizeof(char *) * (nb_word + 1));
    int a = 0;
    int b = 0;

    if (str == NULL)
        return (NULL);
    for (int i = 0; i <= nb_word; i++) {
        tab_array[i] = malloc(sizeof(char *) * (my_strlen(str) + 1));
        my_memset(tab_array[i], '\0', my_strlen(str) + 1);
    }
    tab_array[nb_word] = NULL;
    for (int x = 0; str[x] != '\0'; b++, x++) {
        if (str[x] != '\n' )
            tab_array[a][b] = str[x];
        else if (str[x] == '\n' && str[x + 1] != '\n') {
            tab_array[a][b] = '\0';
            b = -1;
            a++;
        }
    }
    return (tab_array);
}