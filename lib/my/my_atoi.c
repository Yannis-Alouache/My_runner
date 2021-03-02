/*
** EPITECH PROJECT, 2020
** my_atoi.c
** File description:
** atoi
*/

int my_atoi(char *str)
{
    int result = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        result = result * 10 + str[i] - '0';
    return (result);
}