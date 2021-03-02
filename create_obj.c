/*
** EPITECH PROJECT, 2020
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** create_obj
*/

#include "include/my_runner.h"
#include <stdlib.h>
#include <stdio.h>

element_t *create_object(char *path_to_sprite, int x, int y)
{
    element_t *elem = malloc(sizeof(element_t));
    elem->img =
    sfImage_createFromFile(path_to_sprite);
    elem->y = y;
    elem->x = x;
    elem->sprite = sfSprite_create();
    sfTexture *tex = sfTexture_createFromImage(elem->img, NULL);
    sfTexture_setSmooth(tex, 1);
    sfSprite_setTexture(elem->sprite, tex, 0);
    sfVector2f pos = {elem->x, elem->y};
    sfSprite_setPosition(elem->sprite, pos);
    elem->hitbox = get_bound(elem->sprite);
    return (elem);
}

element_t *create_object_spe(char *path_to_sprite, app_t *app)
{
    sfIntRect rect = {0, 0, 262, 155};
    element_t *elem = malloc(sizeof(element_t));
    elem->img =
    sfImage_createFromFile(path_to_sprite);
    elem->sprite = sfSprite_create();
    sfTexture *tex = sfTexture_createFromImage(elem->img, NULL);
    sfTexture_setSmooth(tex, 1);
    sfSprite_setTextureRect(app->player->sprite, rect);
    sfSprite_setTexture(elem->sprite, tex, 0);
    sfVector2f pos = {elem->x, elem->y};
    sfSprite_setPosition(elem->sprite, pos);
    elem->hitbox = get_bound(elem->sprite);
    return (elem);
}

element_t *create_object_ghost(char *path_to_sprite, int x, int y)
{
    sfIntRect rect = {0, 0, 89, 154};
    element_t *elem = malloc(sizeof(element_t));
    elem->img =
    sfImage_createFromFile(path_to_sprite);
    elem->y = y;
    elem->x = x;
    elem->sprite = sfSprite_create();
    sfTexture *tex = sfTexture_createFromImage(elem->img, NULL);
    sfTexture_setSmooth(tex, 1);
    sfSprite_setTextureRect(elem->sprite, rect);
    sfSprite_setTexture(elem->sprite, tex, 0);
    sfVector2f pos = {elem->x, elem->y};
    sfSprite_setPosition(elem->sprite, pos);
    elem->hitbox = get_bound(elem->sprite);
    elem->hitbox->height = 120;
    elem->hitbox->width = elem->hitbox->width - 20;
    elem->hitbox->left = elem->hitbox->left + 10;
    elem->clock = sfClock_create();
    return (elem);
}

element_t *create_object_gato(char *path_to_sprite, int x, int y)
{
    sfIntRect rect = {0, 0, 264, 147};
    element_t *elem = malloc(sizeof(element_t));
    elem->img =
    sfImage_createFromFile(path_to_sprite);
    elem->y = y;
    elem->x = x;
    elem->sprite = sfSprite_create();
    sfTexture *tex = sfTexture_createFromImage(elem->img, NULL);
    sfTexture_setSmooth(tex, 1);
    sfSprite_setTextureRect(elem->sprite, rect);
    sfSprite_setTexture(elem->sprite, tex, 0);
    sfVector2f pos = {elem->x, elem->y};
    sfSprite_setPosition(elem->sprite, pos);
    elem->hitbox = get_bound(elem->sprite);
    elem->hitbox->height = 70;
    elem->hitbox->width = elem->hitbox->width - 100;
    elem->hitbox->left = elem->hitbox->left + 25;
    elem->clock = sfClock_create();
    return (elem);
}