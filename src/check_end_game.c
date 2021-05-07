/*
** EPITECH PROJECT, 2020
** check_end_game.c
** File description:
** check end
*/

#include "runner.h"
#include "my.h"

void stop_game(game_object **obj, framebuffer_t *buffer)
{
    for (int i = 0; obj[i]; i++) {
        obj[i]->speed.x = 0;
        obj[i]->speed.y = 0;
    }
    sfMusic_stop(buffer->game_music);
}

int check_end_game(game_object **obj, framebuffer_t *buffer)
{
    int i = 0;

    for (i = 0; obj[i]; i++);
    if (obj[i - 1]->position.x < 0 - 203 * 0.5) {
        if (obj[5]->indic == 1 && obj[7]->indic == 1 && obj[9]->indic == 1)
            set_sound(buffer->sound, buffer->sound_buffer_w);
        obj[5]->indic = 0;
        obj[7]->indic = 0;
        obj[9]->indic = 0;
        stop_game(obj, buffer);
        return (1);
    }
    return (0);
}