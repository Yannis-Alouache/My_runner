/*
** EPITECH PROJECT, 2020
** create_window.c
** File description:
** create_window
*/

#include "include/my_runner.h"
#include "include/my.h"
#include "stdlib.h"

app_t *init_app2(app_t *app)
{
    gs_t GAME_STATE = MENU;
    app->won = 0;
    app->loose = 0;
    app->win_sound_clock = sfClock_create();
    app->GAME_STATE = GAME_STATE;
    app->menu = init_menu();
    app->cursor = create_object("assets/png/hud/cursor.png", 0, 0);
    app->read_size = 10000;
    return (app);
}

app_t *init_app(char *fps)
{
    app_t *app = malloc(sizeof(app_t));
    app->fps = my_atoi(fps);
    app->window = create_window(app);
    app->background = create_background();
    app->para = init_parralax(app);
    app->player = init_player(app);
    app->camera = init_camera(app);
    app->music = init_music();
    app->win_sound = init_sound(app);
    app->win_sound_counter = 0;
    app->ground_height = 436;
    for (int i = 0; i < 2; i++)
        app->score_txt[i] = init_score(i);
    app->score = 0;
    app->grass_nb = 0;
    app->spike_nb = 0;
    app->tomb_nb = 0;
    return (init_app2(app));
}