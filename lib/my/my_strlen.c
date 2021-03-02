/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** yannis.alouache@epitech.eu
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    return i;
}
