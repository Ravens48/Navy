/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** get_next_line
*/

#include "../../include/get_next_line.h"

char *my_realloc(char *buff, int offset)
{
    char *dest;
    int i = 0;

    buff[offset] = '\0';
    if ((dest = malloc((offset + READ_SIZE + 2) * sizeof(char)))) {
        if (dest == NULL)
            return (NULL);
    }
    i = 0;
    while (buff && buff[i] != '\0') {
        dest[i] = buff[i];
        i++;
    }
    dest[i] = '\0';
    free(buff);
    return (dest);
}

char *my_line(char *buff, int *nbchar, int last)
{
    int i = 0;
    int j = 0;
    char *tmp;

    while (buff[i] != '\n' && buff[i] != '\0')
        i++;
    if (buff && (buff[i] != '\0' || (last == 1 && i > 0))) {
        if ((tmp = malloc((i + 1) * sizeof(char)))) {
            if (!tmp)
                return (NULL);
        }
        while (j < i && buff[j] != '\0') {
            tmp[j] = buff[j];
            j++;
        }
        tmp[j] = '\0';
        j++;
        *nbchar += j;
        return (tmp);
    }
    return (NULL);
}

char *get_next_line(const int fd)
{
    static int offset = 0;
    static int nbchar = 0;
    static char *buff = NULL;
    char *line;
    int len;

    if (buff == NULL) {
        if ((buff = malloc((READ_SIZE + 1) * sizeof(char))))
        buff[0] = '\0';
    }
    if (buff[0] != '\0' && (line = my_line(buff + nbchar, &nbchar, 0)) != NULL)
        return (line);
    while ((len = read(fd, buff + offset, READ_SIZE)) > 0 && (offset += len)
    > 0) {
        if ((buff = my_realloc(buff, offset)))
        if ((line = my_line(buff + nbchar, &nbchar, 0)) != NULL)
            return (line);
    }
    if ((line = my_line(buff + nbchar, &nbchar, 1)) != NULL)
        return (line);
    offset = 0;
    nbchar = 0;
    return (NULL);
}