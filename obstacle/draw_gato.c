/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** draw_gato
*/

#include "SFML/Graphics.h"
#include "../include/my_runner.h"
#include "stdlib.h"

void move_rect_gato(sfIntRect *gato_rect)
{
    switch (gato_rect->left) {
        case 0:
            gato_rect->left = 262;
            break;
        case 262:
            gato_rect->left = 524;
            break;
        case 524:
            gato_rect->left = 786;
            break;
        default:
            gato_rect->left = 0;
            break;
    }
}

void animation_gato(element_t *gato)
{
    sfIntRect gato_rect = sfSprite_getTextureRect(gato->sprite);
    if (sfTime_asSeconds(sfClock_getElapsedTime(gato->clock)) > 0.10f) {
        move_rect_gato(&gato_rect);
        sfSprite_setTextureRect(gato->sprite, gato_rect);
        sfClock_restart(gato->clock);
    }
}

void set_hitbox_gato(sfRectangleShape *hitbox, sfVector2f size, sfVector2f pos)
{
    sfRectangleShape_setSize(hitbox, size);
    sfRectangleShape_setPosition(hitbox, pos);
    sfRectangleShape_setOutlineColor(hitbox, sfRed);
    sfRectangleShape_setOutlineThickness(hitbox, 2);
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
}

void draw_gato(app_t *app)
{
    for (int i = 0; i < app->gato_nb; i++) {
        sfRenderWindow_drawSprite(app->window, app->gato[i]->sprite, NULL);
        sfSprite_setPosition(app->gato[i]->sprite,
        (sfVector2f){app->gato[i]->x, app->gato[i]->y});
        app->gato[i]->x -= 5;
        app->gato[i]->hitbox->left -= 5;
        animation_gato(app->gato[i]);
        sfVector2f size = {app->gato[i]->hitbox->width,
        app->gato[i]->hitbox->height};
        sfVector2f pos = {app->gato[i]->hitbox->left,
        app->gato[i]->hitbox->top};
        app->gato[i]->hitbox->top = app->gato[i]->y + 40;
        sfRectangleShape *hitbox = sfRectangleShape_create();
        set_hitbox_gato(hitbox, size, pos);
    }
}