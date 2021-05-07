/*
** EPITECH PROJECT, 2020
** create_object.c
** File description:
** create object
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "runner.h"
#include <stdlib.h>

void move(game_object *obj, int offset, int reset);

sfIntRect init_rect(int width, int height)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0;
    rect.width = width;
    rect.height = height;
    return (rect);
}

game_object *create_object(const char *sprite_sheet, sfVector2f pos, \
sfIntRect rect)
{
    game_object *obj = malloc(sizeof(game_object));

    if (obj == NULL)
        return (NULL);
    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile(sprite_sheet, NULL);
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    obj->position = pos;
    obj->rect = rect;
    obj->initial_pos = pos;
    sfSprite_setPosition(obj->sprite, obj->position);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    obj->jump = 0;
    obj->indic = 0;
    return (obj);
}