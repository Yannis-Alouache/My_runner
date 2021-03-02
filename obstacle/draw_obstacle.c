/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** draw_obstacle
*/

#include "SFML/Graphics.h"
#include "../include/my_runner.h"
#include "stdlib.h"

void draw_obstacle(app_t *app)
{
    draw_spike(app);
    draw_tomb(app);
    draw_ghost(app);
    draw_gato(app);
}