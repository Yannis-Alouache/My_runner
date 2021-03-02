/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** yannis.alouache@epitech.eu
*/

#include <unistd.h>
#include "my.h"

int my_strlen(char const *str);

char *get_longest_string(char *s1, char *s2)
{
    if (my_strlen(s1) != my_strlen(s2)){
        if (my_strlen(s1) < my_strlen(s2)){
            return (s2);
        }
        if (my_strlen(s1) > my_strlen(s2)){
            return (s1);
        }
    }
    else{
        return (s1);
    }
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    int string_length = my_strlen(get_longest_string(s1, s2));

    for ( i = 0; i < string_length; i++ ) {
        if (s1[i] != s2[i]){
            if ( s1[i] < s2[i]){
                return (-1);
            }
            if (s1[i] > s2[i]){
                return (1);
            }
        }
    }
    return (0);
}
