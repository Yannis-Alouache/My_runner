/*
** EPITECH PROJECT, 2020
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** text
*/

#include "SFML/Graphics.h"
#include "../include/my_runner.h"
#include "stdlib.h"

sfText *init_text(void)
{
    sfFont *font = sfFont_createFromFile("assets/font.TTF");
    sfText *text = sfText_create();
    sfVector2f pos = {380, 400};
    sfText_setFont(text, font);
    sfText_setString(text, "Press Enter");
    sfText_setCharacterSize(text, 60);
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, pos);
    return (text);
}

void draw_text(app_t *app, menu_t *menu)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(menu->text_clock)) < 0.5) {
        sfRenderWindow_drawText(app->window, menu->text, NULL);
    }
    else if (sfTime_asSeconds(sfClock_getElapsedTime(menu->text_clock)) > 1.0) {
        sfClock_restart(menu->text_clock);
    }
}