/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "runner.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "my.h"

int analyse_param(int ac, char **av);

int main(int ac, char **av)
{
    int indic = analyse_param(ac, av);
    if (indic == 84)
        return (84);
    else if (indic == 0)
        return (0);
    framebuffer_t *buffer = init_buffer();
    game_object **obj = init_struct();
    if (buffer == NULL || obj == NULL)
        return (84);
    if (display_window(buffer, obj, av[1]) == 84)
        return (84);
    destroy_buffer(buffer);
    destroy_all(obj);
    return (0);
}