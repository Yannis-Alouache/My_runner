/*
** EPITECH PROJECT, 2020
** my_strstr.c
** File description:
** yannis.alouache@epitech.eu
*/

#include <unistd.h>
#include "my.h"

char *my_strstr(char *str, char *to_find)
{
    int i = 0;
    int j = 0;
    int array_length = my_strlen(to_find);
    if (array_length == 0)
    {
        return (0);
    }
    while (str[i] != '\0'){
        if (str[i] == to_find[j])
            j++;
        else
        {
            j = 0;
        }
        if (j == array_length){
            return (&to_find[0]);
        }
        i++;
    }
    return (0);
}