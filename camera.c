/*
** EPITECH PROJECT, 2020
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** camera
*/

#include "SFML/Graphics.h"
#include "include/my_runner.h"
#include "stdlib.h"

sfView *init_camera(app_t *app)
{
    sfView *camera = sfView_create();
    sfVector2f pos =  {app->player->x + 550, app->ground_height - 115};
    sfVector2f size = {1100, 642};
    sfView_setCenter(camera, pos);
    sfView_setSize(camera, size);
    return (camera);
}

void camera(app_t *app)
{
    sfRenderWindow_setView(app->window, app->camera);
    sfVector2f pos =  {app->player->x + 550, app->ground_height - 115};
    sfVector2f size = {1100, 642};
    sfView_setCenter(app->camera, pos);
    sfView_setSize(app->camera, size);
}

sfFloatRect *camera_bound(sfView *camera)
{
    sfFloatRect *rect = malloc(sizeof(sfFloatRect));
    rect->left = sfView_getCenter(camera).x - sfView_getSize(camera).x / 2;
    rect->top = sfView_getCenter(camera).y - sfView_getSize(camera).y / 2;
    rect->width = sfView_getSize(camera).x;
    rect->height = sfView_getSize(camera).y;
    return (rect);
}