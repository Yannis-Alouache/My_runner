/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** get_elem_nb
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my_runner.h"

int increment_elem_nb2(char c, app_t *app)
{
    if (c == '4') app->ghost_nb += 1;
    if (c == '5') app->gato_nb += 1;
    return (0);
}

int increment_elem_nb(char c, app_t *app)
{
    if (c == '1') app->grass_nb += 1;
    if (c == '2') app->tomb_nb += 1;
    if (c == '3') app->spike_nb += 1;
    return (increment_elem_nb2(c, app));
}

void get_elem_nb(app_t *app, char *path)
{
    int file = open(path, O_RDONLY);
    char *map = malloc(sizeof(char) * app->read_size);
    int eof = read(file, map, app->read_size);
    map[eof] = '\0';
    for (int i = 0; i < eof; i++) {
        increment_elem_nb(map[i], app);
    }
    free(map);
    close(file);
}