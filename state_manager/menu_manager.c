/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** menu_manager
*/

#include "../include/my_runner.h"

void menu_manager(app_t *app)
{
    if (app->GAME_STATE == MENU) {
        menu(app);
    }
}