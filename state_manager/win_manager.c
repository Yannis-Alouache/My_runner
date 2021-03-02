/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** win_manager
*/

#include "../include/my_runner.h"

void win_manager(app_t *app)
{
    if (app->GAME_STATE == WIN) {
        app->final_screen->win = 1;
        app->final_screen->final_txt = init_final_text(app);
        final_screen(app);
    }
}