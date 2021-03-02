/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** test
*/

#include "SFML/Graphics.h"
#include "include/my.h"
#include "include/my_runner.h"
#include "time.h"
#include <stdlib.h>

void get_event(app_t *app)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(app->window, &event)) {
        switch (event.type) {
            case sfEvtClosed:
                sfRenderWindow_close(app->window);
                break;
            case sfEvtMouseButtonPressed:
                check_quit_btn(app, app->final_screen);
                break;
            default:
                break;
        }
    }
}

int check_av(char *fps)
{
    int len = my_strlen(fps);
    for (int i = 0; i < len; i++) {
        if (fps[i] < 48 || fps[i] > 57) {
            my_putstr("fps must be a number\n");
            return (84);
        }
    }
    return (0);
}

void my_runner(app_t *app)
{
    while (sfRenderWindow_isOpen(app->window)) {
        get_event(app);
        state_manager(app);
    }
}

void destroy_sound(app_t *app)
{
    sfMusic_destroy(app->music);
    sfSound_destroy(app->win_sound);
    sfSoundBuffer_destroy(app->sound_buffer);
}

int main(int ac, char **av)
{
    if (ac == 3 && my_strcmp(av[1], "-h") != 0) {
        app_t *app;
        if (check_av(av[2]) == 84) return (84);
        app = init_app(av[2]);
        sfMusic_play(app->music);
        srand(time(NULL));
        if (read_map(app, av[1]) == 84){
            destroy_sound(app);
            my_putstr("wrong map check .legend file\n");
            return (84);
        }
        my_runner(app);
        destroy_sound(app);
        free(app);
    }
    else {
        print_h(ac, av);
    }
    return (0);
}