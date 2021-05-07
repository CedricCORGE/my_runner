/*
** EPITECH PROJECT, 2020
** init_buffer.c
** File description:
** init buffer
*/

#include "my.h"
#include "runner.h"
#include <stdlib.h>

void init_music(framebuffer_t *buffer)
{
    buffer->menu_music = sfMusic_createFromFile("music/menu_music.ogg");
    sfMusic_setLoop(buffer->menu_music, sfTrue);
    sfMusic_setVolume(buffer->menu_music, 100);
    buffer->game_music = sfMusic_createFromFile("music/game_music.ogg");
    sfMusic_setLoop(buffer->game_music, sfTrue);
    sfMusic_setVolume(buffer->game_music, 100);
    sfMusic_play(buffer->menu_music);
}

framebuffer_t *init_buffer(void)
{
    framebuffer_t *buffer = malloc(sizeof(framebuffer_t));
    sfVideoMode mode = {1080, 720, 32};

    if (buffer == NULL)
        return (NULL);
    buffer->window = sfRenderWindow_create(mode, "My Runner", sfClose, NULL);
    init_music(buffer);
    sfRenderWindow_setFramerateLimit(buffer->window, 60);
    buffer->i = 0;
    buffer->sound = sfSound_create();
    buffer->sound_buffer_l = sfSoundBuffer_createFromFile("sound_effect/\
death_sound.wav");
    buffer->sound_buffer_w = sfSoundBuffer_createFromFile("sound_effect/\
victory.wav");
    return (buffer);
}

void destroy_buffer(framebuffer_t *buffer)
{
    sfRenderWindow_destroy(buffer->window);
    sfMusic_destroy(buffer->menu_music);
    sfMusic_destroy(buffer->game_music);
    sfSoundBuffer_destroy(buffer->sound_buffer_w);
    sfSoundBuffer_destroy(buffer->sound_buffer_l);
    sfSound_destroy(buffer->sound);
    free(buffer);
}