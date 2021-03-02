/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** yannis.alouache@epitech.eu
*/

#include <unistd.h>

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int array_length = my_strlen(str);
    int end = my_strlen(str) - 1;
    char str_two[array_length + 1];

    for (int i = 0; i < array_length; i++){
        str_two[i] = str[i];
    }

    for (int start = 0; start <= array_length; start++){
        str[start] = str_two[end];
        end--;
    }

    return (str);
}