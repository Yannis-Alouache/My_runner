/*
** EPITECH PROJECT, 2020
** my_evil_str
** File description:
** yannis.alouache@epitech.eu
*/

int my_strlength(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_evil_str(char *str)
{
    int array_length = my_strlength(str);
    int end = my_strlength(str) - 1;
    char str_two[array_length + 1];

    for (int i = 0; i < array_length; i++) {
        str_two[i] = str[i];
    }

    for (int start = 0; start <= array_length; start++) {
        str[start] = str_two[end];
        end--;
    }

    return (str);

}

