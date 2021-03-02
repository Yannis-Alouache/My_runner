/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** yannis.alouache@epitech.eu
*/
#include "my.h"

void print_ascii_oct(unsigned char c)
{
    if (c <= 9) {
        my_putstr("00");
        my_putstr(integer_to_oct(c));
    }
    else if (c >= 10 && c <= 99) {
        my_putstr("0");
        my_putstr(integer_to_oct(c));
    }
    else
        my_putstr(integer_to_oct(c));
}

int my_spe_putstr(unsigned char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            print_ascii_oct(str[i]);
        }
        else
            my_putchar(str[i]);
        i++;
    }
    return (0);
}
