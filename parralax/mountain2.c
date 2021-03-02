/*
** EPITECH PROJECT, 2020
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** mountain
*/

#include "SFML/Graphics.h"
#include "../include/my_runner.h"
#include "stdlib.h"

void draw_mountain2(app_t *app)
{
    for (int i = 0; i < 3; i++){
        if (sfSprite_getGlobalBounds(app->para->mountain2[i]->sprite).left +
        sfImage_getSize(app->para->mountain2[i]->img).x <=
        camera_bound(app->camera)->left) {
            app->para->mountain2[i]->x = camera_bound(app->camera)->width +
            camera_bound(app->camera)->left;
        }
        sfRenderWindow_drawSprite(app->window, app->para->mountain2[i]->sprite,
        NULL);
        sfVector2f pos = {app->para->mountain2[i]->x,
        app->para->mountain2[i]->y};
        sfSprite_setPosition(app->para->mountain2[i]->sprite, pos);
        app->para->mountain2[i]->x = app->para->mountain2[i]->x - 2;
    }
}

element_t *init_mountain2(app_t *app, int i)
{
    element_t *mountain = malloc(sizeof(element_t));
    mountain->img =
    sfImage_createFromFile("assets/png/environment/mountains.png");
    mountain->y = sfRenderWindow_getSize(app->window).y -
    sfImage_getSize(mountain->img).y + 50;
    if (i == 0) {
        mountain->x = 0;
    }
    if (i == 1) {
        mountain->x = sfImage_getSize(mountain->img).x;
    }
    if (i == 2) {
        mountain->x = sfRenderWindow_getSize(app->window).x;
    }
    mountain->sprite = create_mountain(mountain);
    return (mountain);
}