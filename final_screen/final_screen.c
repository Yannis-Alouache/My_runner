/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** win_screen
*/

#include "SFML/Graphics.h"
#include "../include/my_runner.h"
#include "stdlib.h"

final_screen_t *init_final_screen(app_t *app)
{
    final_screen_t *screen = malloc(sizeof(final_screen_t));
    sfVector2f size = {0.7, 0.7};
    screen->play_again = create_object("assets/png/hud/playAgain.png",
    app->player->x + 440, 360);
    screen->quit = create_object("assets/png/hud/quit.png",
    app->player->x + 440, 460);
    screen->loose = 0;
    screen->win = 0;
    sfSprite_setScale(screen->play_again->sprite, size);
    sfSprite_setScale(screen->quit->sprite, size);
    return (screen);
}

void final_screen(app_t *app)
{
    sfRenderWindow_clear(app->window, sfBlack);
    draw_background(app);
    draw_mountain1(app);
    draw_mountain2(app);
    draw_graveyard(app);
    draw_final_score(app);
    draw_btn(app, app->final_screen);
    draw_final_text(app, app->final_screen);
    draw_cursor(app);
    sfRenderWindow_display(app->window);
}