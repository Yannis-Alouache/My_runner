/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** final_score
*/

#include "SFML/Graphics.h"
#include "../include/my_runner.h"
#include "stdlib.h"

void draw_final_score(app_t *app)
{
    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            sfVector2f pos = {app->player->x + 500, 200};
            sfText_setPosition(app->score_txt[i], pos);
            sfText_setString(app->score_txt[i], "score");
        }
        else if (i == 1) {
            sfVector2f pos = {app->player->x + 520, 245};
            sfText_setPosition(app->score_txt[i], pos);
            handle_score_nb(app, i);
        }
        sfRenderWindow_drawText(app->window, app->score_txt[i], NULL);
    }
}