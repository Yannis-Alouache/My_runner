/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** draw_btn
*/

#include "SFML/Graphics.h"
#include "../include/my_runner.h"
#include "stdlib.h"

void check_quit_btn(app_t *app, final_screen_t *screen)
{
    if (app->GAME_STATE == WIN || app->GAME_STATE == LOOSE) {
        const sfFloatRect hc = sfSprite_getGlobalBounds(app->cursor->sprite);
        const sfFloatRect h2 = sfSprite_getGlobalBounds(screen->quit->sprite);
        if (sfFloatRect_intersects(&hc, &h2, NULL)) {
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                sfRenderWindow_close(app->window);
            }
        }
    }
}

void draw_btn(app_t *app, final_screen_t *screen)
{
    sfRenderWindow_drawSprite(app->window, screen->quit->sprite, NULL);
}

void draw_cursor(app_t *app)
{
    sfVector2f pos = {sfMouse_getPositionRenderWindow(app->window).x +
    app->player->x, sfMouse_getPositionRenderWindow(app->window).y};
    sfSprite_setPosition(app->cursor->sprite, pos);
    sfRenderWindow_drawSprite(app->window, app->cursor->sprite, NULL);
}