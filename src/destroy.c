/*
** EPITECH PROJECT, 2020
** destroy.c
** File description:
** destroy
*/

#include "runner.h"
#include <stdlib.h>

void destroy_object(game_object *obj)
{
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->texture);
    free(obj);
}

void destroy_all(game_object **obj)
{
    for (int i = 0; obj[i]; i++) {
        destroy_object(obj[i]);
    }
}