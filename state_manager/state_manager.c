/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** state_manager
*/

#include "../include/my_runner.h"

void state_manager(app_t *app)
{
    menu_manager(app);
    win_manager(app);
    loose_manager(app);
    game_manager(app);
}