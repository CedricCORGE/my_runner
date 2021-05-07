/*
** EPITECH PROJECT, 2020
** load_map.c
** File description:
** load map
*/

#include "runner.h"
#include "my.h"
#include <stdio.h>

game_object *add_peak(game_object **obj, sfVector2f pos)
{
    game_object *object;

    object = create_object("obstacle/pic.png", pos, \
(sfIntRect){0, 0, 206, 203});
    sfSprite_setScale(object->sprite, (sfVector2f){0.5, 0.5});
    object->type = OBSTACLE;
    object->speed = obj[GROUND_index]->speed;
    object->initial_speed = obj[GROUND_index]->speed;
    return (object);
}

game_object *add_block(game_object **obj, sfVector2f pos)
{
    game_object *object;

    object = create_object("obstacle/block.png", pos, \
(sfIntRect){5, 4, 72, 68});
    sfSprite_setScale(object->sprite, (sfVector2f){1.75, 1.75});
    object->type = BLOCK;
    object->speed = obj[GROUND_index]->speed;
    object->initial_speed = obj[GROUND_index]->speed;
    return (object);
}

int load_text(game_object **obj, char carac, int index, sfVector2f gap)
{
    game_object *object;
    sfVector2f pos = (sfVector2f){1100 + gap.x, 4.5 + gap.y};

    if (carac == '2') {
        object = add_peak(obj, pos);
    } else if (carac == '3') {
        object = add_block(obj, pos);
    } else
        return (-1);
    obj[12 + index] = object;
    return (index + 1);
}