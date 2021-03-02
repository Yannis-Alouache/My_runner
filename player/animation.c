/*
** EPITECH PROJECT, 2020
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** animation
*/

#include "SFML/Graphics.h"
#include "../include/my_runner.h"
#include "stdlib.h"

void move_rect_run(sfIntRect *player_rect)
{
    switch (player_rect->left) {
        case 0:
            player_rect->left = 262;
            break;
        case 262:
            player_rect->left = 524;
            break;
        case 524:
            player_rect->left = 786;
            break;
        case 786:
            player_rect->left = 1048;
            break;
        case 1048:
            player_rect->left = 1310;
            break;
        default:
            player_rect->left = 0;
            break;
    }
}

void move_rect_jump(sfIntRect *player_rect)
{
    switch (player_rect->left) {
        case 0:
            player_rect->left = 262;
            break;
        case 262:
            player_rect->left = 524;
            break;
        default:
            player_rect->left = 0;
            break;
    }
}

void  handle_animation(app_t *app, sfIntRect *player_rect)
{
    if (app->loose == 0 && app->won == 0 && app->player->running == 1){
        app->player->sprite = create_object_spe
        ("assets/png/sprites/hero/hero_run/hero_run.png", app)->sprite;
        move_rect_run(player_rect);
    }
    else if (app->loose == 0 && app->won == 0 && app->player->running == 0) {
        app->player->sprite = create_object_spe
        ("assets/png/sprites/hero/hero_jump/hero_jump.png", app)->sprite;
        player_rect->left = 0;
        move_rect_jump(player_rect);
    }
    else {
        app->player->sprite = create_object
        ("assets/png/sprites/hero.png", 0, 0)->sprite;
        player_rect->left = 0;
    }
}

void animation(app_t *app)
{
    sfIntRect player_rect = sfSprite_getTextureRect(app->player->sprite);
    if (sfTime_asSeconds(sfClock_getElapsedTime(app->player->clock)) > 0.15f) {
        handle_animation(app, &player_rect);
        sfSprite_setTextureRect(app->player->sprite, player_rect);
        sfClock_restart(app->player->clock);
    }
}