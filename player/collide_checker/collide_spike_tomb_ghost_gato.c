/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** collide_spike_tomb
*/

#include "SFML/Graphics.h"
#include "../../include/my_runner.h"
#include "stdlib.h"

int check_collide_spike(app_t *app)
{
    for (int i = 0; i < app->spike_nb; i++) {
        if (sfFloatRect_intersects(app->player->hitbox,
        app->spike[i]->hitbox, NULL)) {
            return (1);
        }
    }
    return (0);
}

int check_collide_tomb(app_t *app)
{
    for (int i = 0; i < app->tomb_nb; i++) {
        if (sfFloatRect_intersects(app->player->hitbox,
        app->tomb[i]->hitbox, NULL)) {
            return (1);
        }
    }
    return (0);
}

int check_collide_ghost(app_t *app)
{
    for (int i = 0; i < app->ghost_nb; i++) {
        if (sfFloatRect_intersects(app->player->hitbox,
        app->ghost[i]->hitbox, NULL)) {
            return (1);
        }
    }
    return (0);
}

int check_collide_gato(app_t *app)
{
    for (int i = 0; i < app->gato_nb; i++) {
        if (sfFloatRect_intersects(app->player->hitbox,
        app->gato[i]->hitbox, NULL)) {
            return (1);
        }
    }
    return (0);
}