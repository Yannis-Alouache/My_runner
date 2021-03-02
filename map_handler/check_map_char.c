/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** check_map_char
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my_runner.h"

void spawn_grass(char c, app_t *app, counter_t *count, sfVector2i pos)
{
    if (c == '1') {
        app->grass[count->grass] = create_object
        ("assets/png/environment/grass.png", pos.x, pos.y);
        count->grass += 1;
    }
}

void spawn_tomb(char c, app_t *app, counter_t *count, sfVector2i pos)
{
    if (c == '2') {
        app->tomb[count->tomb] = create_object
        ("assets/png/environment/sliced_objects/stone.png", pos.x, pos.y + 25);
        count->tomb += 1;
    }
}

void spawn_spike(char c, app_t *app, counter_t *count, sfVector2i pos)
{
    if (c == '3') {
        app->spike[count->spike] = create_object
        ("assets/png/environment/sliced_objects/spike.png", pos.x, pos.y + 70);
        count->spike += 1;
    }
}

void spawn_ghost(app_t *app, counter_t *count, sfVector2i pos)
{
    app->ghost[count->ghost] = create_object_ghost
    ("assets/png/sprites/ghost_halo/ghost_halo.png", pos.x, pos.y - 40);
    sfSprite_setScale(app->ghost[count->ghost]->sprite,
    (sfVector2f){0.95, 0.95});
    count->ghost += 1;
}

void spawn_gato(app_t *app, counter_t *count, sfVector2i pos)
{
    app->gato[count->gato] = create_object_gato
    ("assets/png/sprites/hell_gato/hell_gato.png", pos.x, pos.y);
    sfSprite_setScale(app->gato[count->gato]->sprite,
    (sfVector2f){0.85, 0.85});
    count->gato += 1;
}