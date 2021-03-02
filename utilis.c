/*
** EPITECH PROJECT, 2020
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** utilis
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/my_runner.h"

counter_t *init_counter(void)
{
    counter_t *counter = malloc(sizeof(counter_t));
    counter->grass = 0;
    counter->tomb = 0;
    counter->spike = 0;
    counter->ghost = 0;
    counter->gato = 0;
    return (counter);
}

void malloc_game_obj(app_t *app)
{
    app->grass = malloc(sizeof(struct element_t *) * app->grass_nb);
    app->tomb = malloc(sizeof(struct element_t *) * app->tomb_nb);
    app->spike = malloc(sizeof(struct element_t *) * app->spike_nb);
    app->ghost = malloc(sizeof(struct element_t *) * app->ghost_nb);
    app->gato = malloc(sizeof(struct element_t *) * app->gato_nb);
}

sfFloatRect *get_bound(sfSprite *sprite)
{
    sfFloatRect *rect = malloc(sizeof(sfFloatRect));
    rect->width = sfSprite_getGlobalBounds(sprite).width;
    rect->left = sfSprite_getGlobalBounds(sprite).left;
    rect->top = sfSprite_getGlobalBounds(sprite).top;
    rect->height = sfSprite_getGlobalBounds(sprite).height;
    return (rect);
}

int random_between(int min, int max)
{
    int random = (rand() % (max - min + 1)) + min;
    return (random);
};