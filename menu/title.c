/*
** EPITECH PROJECT, 2020
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** title
*/

#include "SFML/Graphics.h"
#include "../include/my_runner.h"
#include "stdlib.h"

element_t *init_title(void)
{
    element_t *title = create_object
    ("assets/png/hud/gothicvania.png", 25, -100);
    sfVector2f scale = {0.8, 0.8};
    sfSprite_setScale(title->sprite, scale);
    return (title);
}

void draw_title(app_t *app, menu_t *menu)
{
    sfRenderWindow_drawSprite(app->window, menu->title->sprite, NULL);
}