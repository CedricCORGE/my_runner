/*
** EPITECH PROJECT, 2020
** music.c
** File description:
** initialize music
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "my.h"

sfMusic *set_music(void)
{
    sfMusic *music;
    music = sfMusic_createFromFile("music/music.ogg");
    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, 100);
    return (music);
}