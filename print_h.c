/*
** EPITECH PROJECT, 2020
** print_h.c
** File description:
** print_h
*/
#include "stdlib.h"
#include "include/my.h"

void print_h(int ac, char **av)
{
    if (ac == 2 && my_strstr(av[1], "-h")) {
        my_putstr("Finite runner created with CSFML.\n\n");
        my_putstr("USAGE\n ./my_runner map fps\n\n\n");
        my_putstr("OPTIONS\n\n");
        my_putstr("-h\t\tprint the usage and quit.\n\n");
        my_putstr("USER INTERACTIONS\n");
        my_putstr(" SPACE_KEY\tjump.\n");
        my_putstr("\nMAP\n");
        my_putstr("\tYou can edit the map file to create a map\n");
        my_putstr("\tYou can see the legend in the .legend file\n");
        my_putstr("\tYou can put obstacle but monsters appear randomly\n");
        my_putstr("\tHAVE FUN !\n");

    }
}