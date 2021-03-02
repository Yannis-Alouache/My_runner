/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** check_map_error
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my_runner.h"
#include "../include/my.h"

int check_map_line_error(char *map)
{
    int i = 0;
    int counter = 0;
    while (map[i] != '\0') {
        if (map[i] == '\n') {
            counter += 1;
        }
        i++;
    }
    if (counter != 6) {
        return (1);
    }
    return (0);
}

int char_in_str(char a)
{
    char str[] = "0123\n";
    int counter = 0;
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == a) {
            counter += 1;
        }
    }
    if (counter == 1) {
        return (1);
    }
    return (0);
}

int check_map_char_error(char *map, int eof)
{
    for (int i = 0; i < eof; i++) {
        if (char_in_str(map[i]) == 0) {
            return (1);
        }
    }
    return (0);
}

int check_map_error(char *path, app_t *app)
{
    int file = open(path, O_RDONLY);
    char *map = malloc(sizeof(char) * app->read_size);
    int eof = read(file, map, app->read_size);
    map[eof] = '\0';
    int line_err = check_map_line_error(map);
    int char_err = check_map_char_error(map, eof);
    free(map);
    close(file);
    if (line_err == 1 || char_err == 1) {
        return (1);
    }
    else
        return (0);
}