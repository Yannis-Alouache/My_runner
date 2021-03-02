/*
** EPITECH PROJECT, 2020
** create_window.c
** File description:
** create_window
*/

#include "SFML/Graphics.h"
#include "include/my_runner.h"

sfRenderWindow *create_window(app_t *app)
{
    sfVideoMode mode = {1100, 642, 32};
    sfVector2i pos = {1980 / 2 - (1150 / 2) - 50, 1080 / 2 - (642 / 2)};
    sfRenderWindow *window = sfRenderWindow_create(mode,
    "My_runner", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, app->fps);
    sfRenderWindow_setMouseCursorVisible(window, 0);
    sfRenderWindow_setKeyRepeatEnabled( window, 0);
    sfRenderWindow_setPosition(window, pos);
    return (window);
}

sfSprite *create_background(void)
{
    sfTexture *tex = sfTexture_createFromFile(
    "assets/png/environment/background.png",
    NULL);
    sfTexture_setSmooth(tex, 1);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, tex, 1);
    return (sprite);
}

void draw_background(app_t *app)
{
    sfRenderWindow_drawSprite(app->window, app->background, NULL);
    sfSprite_setPosition(app->background, (sfVector2f){app->player->x, 0});
    if (app->final_screen != NULL && app->final_screen->loose == 1)
        sfSprite_setPosition(app->background,
        (sfVector2f){app->player->x - 6, 0});
}