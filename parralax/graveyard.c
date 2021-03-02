/*
** EPITECH PROJECT, 2020
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** mountain
*/

#include "SFML/Graphics.h"
#include "../include/my_runner.h"
#include "stdlib.h"

sfSprite *create_graveyard(element_t *graveyard)
{
    sfTexture *tex = sfTexture_createFromFile(
    "assets/png/environment/graveyard.png",
    NULL);
    sfTexture_setSmooth(tex, 1);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, tex, 1);
    sfVector2f pos = {graveyard->x, graveyard->y};
    sfSprite_setPosition(sprite, pos);
    return (sprite);
}

void draw_graveyard(app_t *app)
{
    for (int i = 0; i < 3; i++){
        if (sfSprite_getGlobalBounds(app->para->graveyard[i]->sprite).left +
        sfImage_getSize(app->para->graveyard[i]->img).x
        <= camera_bound(app->camera)->left) {
            app->para->graveyard[i]->x =
            camera_bound(app->camera)->width + camera_bound(app->camera)->left;
        }
        sfRenderWindow_drawSprite(app->window,
        app->para->graveyard[i]->sprite, NULL);
        sfSprite_setPosition(app->para->graveyard[i]->sprite, (sfVector2f)
        {app->para->graveyard[i]->x, app->para->graveyard[i]->y});
        app->para->graveyard[i]->x -= 3;
    }
}

element_t *init_graveyard(app_t *app, int i)
{
    element_t *graveyard = malloc(sizeof(element_t));
    graveyard->img =
    sfImage_createFromFile("assets/png/environment/graveyard.png");
    graveyard->y = sfRenderWindow_getSize(app->window).y -
    sfImage_getSize(graveyard->img).y;
    if (i == 0) {
        graveyard->x = 0;
    }
    if (i == 1) {
        graveyard->x = sfImage_getSize(graveyard->img).x;
    }
    if (i == 2) {
        graveyard->x = sfRenderWindow_getSize(app->window).x - 1;
    }
    graveyard->sprite = create_graveyard(graveyard);
    return (graveyard);
}