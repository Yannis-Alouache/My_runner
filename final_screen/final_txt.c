/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** win_txt
*/

#include "SFML/Graphics.h"
#include "../include/my_runner.h"
#include "stdlib.h"

sfText *init_final_text(app_t *app)
{
    sfFont *font = sfFont_createFromFile("assets/font.TTF");
    sfText *text = sfText_create();
    sfVector2f pos_win = {app->player->x + 355, 90};
    sfVector2f pos_loose = {app->player->x + 410, 90};
    sfText_setFont(text, font);
    if (app->final_screen->loose == 1) {
        sfText_setString(text, "You Died !");
        sfText_setPosition(text, pos_loose);
    }
    else if (app->final_screen->win == 1) {
        sfText_setString(text, "You Survived !");
        sfText_setPosition(text, pos_win);
    }
    sfText_setCharacterSize(text, 60);
    sfText_setColor(text, sfWhite);
    return (text);
}

void draw_final_text(app_t *app, final_screen_t *screen)
{
    sfRenderWindow_drawText(app->window, screen->final_txt, NULL);
}