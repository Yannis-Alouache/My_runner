/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** yannis.alouache@epitech.eu
*/

void my_swap(int *a, int *b)
{
    int result_a = *a;
    int result_b = *b;

    *a = result_b;
    *b = result_a;
}
