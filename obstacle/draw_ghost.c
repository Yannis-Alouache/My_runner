/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** draw_ghost
*/

#include "SFML/Graphics.h"
#include "../include/my_runner.h"
#include "stdlib.h"

void move_rect_ghost(sfIntRect *ghost_rect)
{
    switch (ghost_rect->left) {
        case 0:
            ghost_rect->left = 89;
            break;
        case 89:
            ghost_rect->left = 178;
            break;
        case 178:
            ghost_rect->left = 267;
            break;
        default:
            ghost_rect->left = 0;
            break;
    }
}

void animation_ghost(element_t *ghost)
{
    sfIntRect ghost_rect = sfSprite_getTextureRect(ghost->sprite);
    if (sfTime_asSeconds(sfClock_getElapsedTime(ghost->clock)) > 0.15f) {
        move_rect_ghost(&ghost_rect);
        sfSprite_setTextureRect(ghost->sprite, ghost_rect);
        sfClock_restart(ghost->clock);
    }
}

void set_hitbox_ghost(sfRectangleShape *hitbox, sfVector2f size, sfVector2f pos)
{
    sfRectangleShape_setSize(hitbox, size);
    sfRectangleShape_setPosition(hitbox, pos);
    sfRectangleShape_setOutlineColor(hitbox, sfRed);
    sfRectangleShape_setOutlineThickness(hitbox, 2);
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
}

void draw_ghost(app_t *app)
{
    for (int i = 0; i < app->ghost_nb; i++) {
        sfRenderWindow_drawSprite(app->window, app->ghost[i]->sprite, NULL);
        sfSprite_setPosition(app->ghost[i]->sprite,
        (sfVector2f){app->ghost[i]->x, app->ghost[i]->y});
        app->ghost[i]->x -= 3;
        app->ghost[i]->hitbox->left -= 3;
        animation_ghost(app->ghost[i]);
        sfVector2f size = {app->ghost[i]->hitbox->width,
        app->ghost[i]->hitbox->height};
        sfVector2f pos = {app->ghost[i]->hitbox->left,
        app->ghost[i]->hitbox->top};
        app->ghost[i]->hitbox->top = app->ghost[i]->y + 32;
        sfRectangleShape *hitbox = sfRectangleShape_create();
        set_hitbox_ghost(hitbox, size, pos);
    }
}