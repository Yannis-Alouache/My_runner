/*
** EPITECH PROJECT, 2020
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** score
*/

#include "SFML/Graphics.h"
#include "include/my_runner.h"
#include "stdlib.h"
#include "include/my.h"

static int get_array_len(long int nb)
{
    int result;
    int tmp = nb;
    int i = 0;

    while (tmp != 0) {
        i++;
        tmp = tmp / 10;
    }
    if (i == 0)
        i = 1;
    result = i;
    return (result);
}

char *get_score_str(app_t *app)
{
    char *str = malloc(sizeof(char) * (get_array_len(app->score) + 1));
    int n = app->score;
    int i = 0;
    while (n > 0) {
        str[i] = n % 10 + '0';
        i++;
        n = n / 10;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}

sfText *init_score(int i)
{
    sfFont *font = sfFont_createFromFile("assets/font.TTF");
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setString(text, "score");
    if (i == 1)
        sfText_setCharacterSize(text, 33);
    if (i == 0)
        sfText_setCharacterSize(text, 40);
    sfText_setColor(text, sfWhite);
    return (text);
}

void handle_score_nb(app_t *app, int i)
{
    if (app->score == 0)
        sfText_setString(app->score_txt[i], "0");
    else
        sfText_setString(app->score_txt[i], get_score_str(app));
}

void draw_score(app_t *app)
{
    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            sfVector2f pos = {app->player->x, 0};
            sfText_setPosition(app->score_txt[i], pos);
            sfText_setString(app->score_txt[i], "score");
        }
        else if (i == 1) {
            sfVector2f pos = {app->player->x + 110, 5};
            sfText_setPosition(app->score_txt[i], pos);
            handle_score_nb(app, i);
        }
        sfRenderWindow_drawText(app->window, app->score_txt[i], NULL);
    }
}