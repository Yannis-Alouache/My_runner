/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** loose_manager
*/

#include "../include/my_runner.h"

void loose_manager(app_t *app)
{
    if (app->GAME_STATE == LOOSE) {
        app->final_screen->loose = 1;
        app->final_screen->final_txt = init_final_text(app);
        final_screen(app);
    }
}