/*
** EPITECH PROJECT, 2020
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** win_or_loose
*/

#include "SFML/Graphics.h"
#include "../include/my_runner.h"
#include "stdlib.h"

void win_or_loose(app_t *app)
{
    if (check_collide_obstacle(app)) {
        app->final_screen = init_final_screen(app);
        app->GAME_STATE = LOOSE;
    }
    else if (app->player->x > app->grass[app->grass_nb - 1]->x -
    (app->grass[0]->hitbox->width / 2)) {
        app->final_screen = init_final_screen(app);
        app->won = 1;
    }
}