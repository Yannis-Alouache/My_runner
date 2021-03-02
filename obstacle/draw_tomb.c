/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** draw_tomb
*/

#include "SFML/Graphics.h"
#include "../include/my_runner.h"
#include "stdlib.h"

void draw_tomb(app_t *app)
{
    for (int i = 0; i < app->tomb_nb; i++) {
        sfRenderWindow_drawSprite(app->window, app->tomb[i]->sprite, NULL);
        sfVector2f size = {app->tomb[i]->hitbox->width,
        app->tomb[i]->hitbox->height};
        sfVector2f pos = {app->tomb[i]->hitbox->left,
        app->tomb[i]->hitbox->top};
        sfRectangleShape *hitbox = sfRectangleShape_create();
        sfRectangleShape_setSize(hitbox, size);
        sfRectangleShape_setPosition(hitbox, pos);
        sfRectangleShape_setOutlineColor(hitbox, sfRed);
        sfRectangleShape_setOutlineThickness(hitbox, 2);
        sfRectangleShape_setFillColor(hitbox, sfTransparent);
    }
}