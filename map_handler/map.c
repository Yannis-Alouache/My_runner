/*
** EPITECH PROJECT, 2020
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** map
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my_runner.h"

static void space_sprite(sfVector2i *pos, char *map, int i)
{
    pos->x += 139;
    if (map[i] == '\n') {
        pos->y += 91;
        pos->x = 0;
    }
}

int check_prox(sfVector2i pos, app_t *app)
{
    if (pos.x <= app->player->x + 800) {
        return (0);
    }
    for (int i = 0; i < app->ghost_nb; i++) {
        if (pos.x <= app->ghost[i]->x + 800)
            return (0);
    }
    for (int i = 0; i < app->gato_nb; i++) {
        if (pos.x <= app->gato[i]->x + 800)
            return (0);
    }
    return (1);
}

static void spawn_element(char c, app_t *app, counter_t *count, sfVector2i pos)
{
    int rand_nb = random_between(0, 100);
    int rand_nb2;
    if (pos.y == 455) {
        if (rand_nb < 10) {
            rand_nb2 = random_between(1, 3);
            if ((rand_nb2 == 1 || rand_nb2 == 3)
            && check_prox(pos, app) == 1) {
                spawn_ghost(app, count, pos);
                app->ghost_nb += 1;
            }
            else if (rand_nb2 == 2 && check_prox(pos, app) == 1) {
                spawn_gato(app, count, pos);
                app->gato_nb += 1;
            }
        }
    }
    spawn_grass(c, app, count, pos);
    spawn_spike(c, app, count, pos);
    spawn_tomb(c, app, count, pos);
}

int read_map(app_t *app, char *path)
{
    if (check_map_error(path, app) == 1) return (84);
    get_elem_nb(app, path);
    counter_t *counter = init_counter();
    int file = open(path, O_RDONLY);
    char *map = malloc(sizeof(char) * app->read_size);
    int eof = read(file, map, app->read_size);
    sfVector2i pos = {0, 0};
    malloc_game_obj(app);
    for (int i = 0; i < eof; i++) {
        spawn_element(map[i], app, counter, pos);
        space_sprite(&pos, map, i);
    }
    return (0);
}