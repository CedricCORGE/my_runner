/*
** EPITECH PROJECT, 2020
** sound_effect.c
** File description:
** sound effect
*/

#include "runner.h"

void set_sound(sfSound *sound, sfSoundBuffer *sound_buffer)
{
    sfSound_setBuffer(sound, sound_buffer);
    sfSound_play(sound);
}