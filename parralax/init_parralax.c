/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** init_parralax
*/

#include "SFML/Graphics.h"
#include "../include/my_runner.h"
#include "stdlib.h"

parralax_t *init_parralax(app_t *app)
{
    parralax_t *parralax = malloc(sizeof(parralax_t));
    for (int i = 0; i < 3; i++) {
        parralax->mountain1[i] = init_mountain1(app, i);
        parralax->mountain2[i] = init_mountain2(app, i);
        parralax->graveyard[i] = init_graveyard(app, i);
    }
    return (parralax);
}