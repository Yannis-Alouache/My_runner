/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** draw_spike
*/

#include "SFML/Graphics.h"
#include "../include/my_runner.h"
#include "stdlib.h"

void draw_spike(app_t *app)
{
    for (int i = 0; i < app->spike_nb; i++) {
        sfRenderWindow_drawSprite(app->window, app->spike[i]->sprite, NULL);
        sfVector2f size = {app->spike[i]->hitbox->width,
        app->spike[i]->hitbox->height};
        sfVector2f pos = {app->spike[i]->hitbox->left,
        app->spike[i]->hitbox->top};
        app->spike[i]->hitbox->top = app->spike[i]->y + 10;
        sfRectangleShape *hitbox = sfRectangleShape_create();
        sfRectangleShape_setSize(hitbox, size);
        sfRectangleShape_setPosition(hitbox, pos);
        sfRectangleShape_setOutlineColor(hitbox, sfRed);
        sfRectangleShape_setOutlineThickness(hitbox, 2);
        sfRectangleShape_setFillColor(hitbox, sfTransparent);
    }
}