/*
** EPITECH PROJECT, 2020
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** hitbox
*/

#include "SFML/Graphics.h"
#include "../include/my_runner.h"
#include "stdlib.h"

sfFloatRect *get_player_hitbox(player_t *player)
{
    sfFloatRect *hitbox = malloc(sizeof(sfFloatRect));
    hitbox = get_bound(player->sprite);
    hitbox->width = get_bound(player->sprite)->width / 6 - 200;
    hitbox->left = get_bound(player->sprite)->left + 100;
    hitbox->top = get_bound(player->sprite)->top + 50;
    hitbox->height = get_bound(player->sprite)->height - 50;
    return (hitbox);
}

void draw_player_hitbox(app_t *app)
{
    sfVector2f size = {app->player->hitbox->width, app->player->hitbox->height};
    sfVector2f pos = {app->player->hitbox->left, app->player->hitbox->top};
    sfRectangleShape *hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(hitbox, size);
    app->player->hitbox->left += app->player->vel_x;
    app->player->hitbox->top = app->player->y + 50;
    sfRectangleShape_setPosition(hitbox, pos);
    sfRectangleShape_setOutlineColor(hitbox, sfRed);
    sfRectangleShape_setOutlineThickness(hitbox, 2);
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
}