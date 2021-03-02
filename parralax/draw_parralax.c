/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** draw_parralax
*/

#include "SFML/Graphics.h"
#include "../include/my_runner.h"
#include "stdlib.h"

void draw_parralax(app_t *app)
{
    draw_background(app);
    draw_mountain1(app);
    draw_mountain2(app);
    draw_graveyard(app);
}