/*
** EPITECH PROJECT, 2020
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** jump
*/

#include "SFML/Graphics.h"
#include "../include/my_runner.h"
#include "stdlib.h"

void jump(app_t *app)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) &&
    app->player->y == app->ground_height && app->won == 0 && app->loose == 0) {
        app->player->running = 0;
        app->player->jumping = sfTrue;
        app->player->vel_y = -20;
        app->player->vel_x += 2;
        app->player->gravity = 5;
        app->player->jump_count += 1;
    }
    if (app->player->jumping == sfTrue) {
        app->player->y += app->player->vel_y;
        if (app->player->y <= app->ground_height - 300) {
            app->player->jumping = sfFalse;
        }
    }
}

void apply_gravity(app_t *app)
{
    app->player->y += app->player->gravity;
    if (app->player->hitbox->top + app->player->hitbox->height >
    app->grass[0]->hitbox->top) {
        app->player->y -= (app->player->hitbox->top +
        app->player->hitbox->height) - app->grass[0]->hitbox->top;
        app->player->gravity = 0;
        app->player->running = 1;
    }
}