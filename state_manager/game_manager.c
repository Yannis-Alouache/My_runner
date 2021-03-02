/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** game_manager
*/

#include "../include/my_runner.h"

void game_manager(app_t *app)
{
    if (app->GAME_STATE == PLAY) {
        sfRenderWindow_clear(app->window, sfBlack);
        camera(app);
        draw_parralax(app);
        draw_obstacle(app);
        draw_grass(app);
        app->player->x += app->player->vel_x;
        draw_player(app);
        draw_score(app);
        if (!app->won) app->score += 1;
        sfRenderWindow_display(app->window);
        if (app->won) {
            play_win_sound(app);
            if (sfTime_asSeconds(sfClock_getElapsedTime(app->win_sound_clock))
            > 2.0f) {
                app->GAME_STATE = WIN;
                app->won = 0;
            }
        }
    }
}