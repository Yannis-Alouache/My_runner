/*
** EPITECH PROJECT, 2020
** my_printf.c
** File description:
** my_printf
*/

#include "my.h"

void my_spe_put_nbr(unsigned int n)
{
    int mod = 0;
    if (n <= 9 && n >= 0)
        my_putchar(n + 48);
    if (n > 9) {
        mod = n % 10;
        my_put_nbr(n / 10);
        my_putchar(mod + 48);
    }
}