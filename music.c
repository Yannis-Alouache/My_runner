/*
** EPITECH PROJECT, 2020
** B-MUL-100-LIL-1-1-myrunner-yannis.alouache
** File description:
** music
*/

#include "SFML/Audio.h"
#include "include/my_runner.h"

sfMusic *init_music(void)
{
    sfMusic *music = sfMusic_createFromFile("assets/ost.ogg");
    sfMusic_setLoop(music, 1);
    sfMusic_setVolume(music, 100.0);
    return (music);
}

sfSound *init_sound(app_t *app)
{
    sfSoundBuffer *buff = sfSoundBuffer_createFromFile("assets/win.ogg");
    app->sound_buffer = buff;
    sfSound *sound = sfSound_create();
    sfSound_setBuffer(sound, buff);
    sfSound_setVolume(sound, 100.0);
    return (sound);
}

void play_win_sound(app_t *app)
{
    if (app->win_sound_counter == 0) {
        app->player->y = 436;
        sfSound_play(app->win_sound);
        sfClock_restart(app->win_sound_clock);
        sfMusic_setVolume(app->music, 20.0);
        app->win_sound_counter += 1;
    }
    app->player->vel_x = 0;
}