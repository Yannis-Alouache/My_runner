/*
** EPITECH PROJECT, 2020
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** player
*/

#include "SFML/Graphics.h"
#include "../include/my_runner.h"
#include "stdlib.h"

sfSprite *create_player(player_t *player)
{
    sfTexture *tex = sfTexture_createFromFile(
    "assets/png/sprites/hero/hero_run/hero_run.png",
    NULL);
    sfTexture_setSmooth(tex, 1);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, tex, 1);
    sfVector2f pos = {player->x, player->y};
    sfSprite_setPosition(sprite, pos);
    return (sprite);
}

void manage_jump(app_t *app)
{
    jump(app);
    apply_gravity(app);
    if (app->player->hitbox->top + app->player->hitbox->height <
    app->grass[0]->hitbox->top) {
        app->player->y += app->player->gravity;
    }
    if (app->player->jump_count != app->player->jump_count2 &&
    app->player->y == 436) {
        app->player->vel_x -= 2;
        app->player->jump_count2 += 1;
    }
}

void draw_player(app_t *app)
{
    sfIntRect rect = {0, 0, 262, 155};
    if (app->player->fs == 0) {
        sfSprite_setTextureRect(app->player->sprite, rect);
        app->player->fs = 1;
    }
    animation(app);
    manage_jump(app);
    sfVector2f pos = {app->player->x, app->player->y};
    sfSprite_setPosition(app->player->sprite, pos);
    sfRenderWindow_drawSprite(app->window, app->player->sprite, NULL);
    win_or_loose(app);
    draw_player_hitbox(app);
}

player_t *init_player(app_t *app)
{
    player_t *player = malloc(sizeof(player_t));
    player->img =
    sfImage_createFromFile("assets/png/sprites/hero/hero_run/hero_run.png");
    player->y = sfRenderWindow_getSize(app->window).y -
    sfImage_getSize(player->img).y - 60;
    player->x = 0;
    player->sprite = create_player(player);
    player->vel_x = 3;
    player->vel_y = 0;
    player->fs = 0;
    player->hitbox = get_player_hitbox(player);
    player->clock = sfClock_create();
    player->gravity = 5.0f;
    player->jump_count = 0;
    player->jump_count2 = 0;
    player->running = 1;
    return (player);
}