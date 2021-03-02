/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** yannis.alouache@epitech.eu
*/
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int array_size = my_strlen(dest) + my_strlen(src);
    int little_size = my_strlen(dest);

    while (i < array_size){
        if (dest[i] == '\0'){
            dest[i] = src[i - little_size];
        }
        i++;
    }
    dest[i] = '\0';

    return (dest);
}