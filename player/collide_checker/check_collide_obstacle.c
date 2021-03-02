/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** check_collide_all
*/

#include "SFML/Graphics.h"
#include "../../include/my_runner.h"
#include "stdlib.h"

sfBool check_collide_obstacle2(app_t *app)
{
    if (check_collide_gato(app))
        return (1);
    return (0);
}

sfBool check_collide_obstacle(app_t *app)
{
    if (check_collide_spike(app))
        return (1);
    if (check_collide_tomb(app))
        return (1);
    if (check_collide_ghost(app))
        return (1);
    return (check_collide_obstacle2(app));
}