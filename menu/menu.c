/*
** EPITECH PROJECT, 2020
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** menu
*/

#include "SFML/Graphics.h"
#include "../include/my_runner.h"
#include "stdlib.h"

menu_t *init_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));
    menu->title = init_title();
    menu->text = init_text();
    menu->text_clock = sfClock_create();
    return (menu);
}

void menu(app_t *app)
{
    sfRenderWindow_clear(app->window, sfBlue);
    draw_background(app);
    draw_mountain1(app);
    draw_mountain2(app);
    draw_graveyard(app);
    draw_title(app, app->menu);
    draw_text(app, app->menu);
    if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
        app->GAME_STATE = PLAY;
    }
    sfRenderWindow_display(app->window);
}