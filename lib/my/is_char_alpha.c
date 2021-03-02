/*
** EPITECH PROJECT, 2020
** is_char_alpha.c
** File description:
** yannis.alouache@epitech.eu
*/

int is_char_alpha(char letter)
{
    if (letter >= 97 && letter <= 122){
        return (1);
    }
    if (letter >= 65 && letter <= 90){
        return (1);
    }

    return (0);
}
