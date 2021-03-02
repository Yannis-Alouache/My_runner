/*
** EPITECH PROJECT, 2020
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** mountain
*/

#include "SFML/Graphics.h"
#include "include/my_runner.h"
#include "stdlib.h"

sfSprite *create_grass(element_t *grass)
{
    sfTexture *tex = sfTexture_createFromFile(
    "assets/png/Environment/grass.png",
    NULL);
    sfTexture_setSmooth(tex, 1);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, tex, 1);
    sfVector2f pos = {grass->x, grass->y};
    sfSprite_setPosition(sprite, pos);
    return (sprite);
}

static void draw_grass_hitbox(app_t *app, int i)
{
    sfVector2f size = {app->grass[i]->hitbox->width,
    app->grass[i]->hitbox->height};
    sfVector2f pos = {app->grass[i]->hitbox->left, app->grass[i]->hitbox->top};
    sfRectangleShape *hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(hitbox, size);
    app->grass[i]->hitbox->top = app->grass[i]->y + 45;
    sfRectangleShape_setPosition(hitbox, pos);
    sfRectangleShape_setOutlineColor(hitbox, sfRed);
    sfRectangleShape_setOutlineThickness(hitbox, 2);
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
}

void draw_grass(app_t *app)
{
    for (int i = 0; i < app->grass_nb; i++) {
        sfRenderWindow_drawSprite(app->window, app->grass[i]->sprite, NULL);
        draw_grass_hitbox(app, i);
    }
}

element_t *custom_init_grass(int x, int y)
{
    element_t *grass = malloc(sizeof(element_t));
    grass->img =
    sfImage_createFromFile("assets/png/Environment/grass.png");
    grass->y = y;
    grass->x = x;
    grass->sprite = create_grass(grass);
    grass->hitbox = get_bound(grass->sprite);
    return (grass);
}