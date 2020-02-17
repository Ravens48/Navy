/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** coucou
*/

void my_putchar(char c);

int my_put_nbr(int n)
{
    int p = 1;
    int temp = n;
    int keep = 0;

    if (n < 0)
    {
        temp *= -1;
        my_putchar('-');
    }
    while (temp / p > 9) {
        p = p  * 10;
    }
    while (p > 0) {
        keep = temp / p + 48;
        temp = temp % p;
        p /= 10;
        my_putchar(keep);
    }
    return (0);
}