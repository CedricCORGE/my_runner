/*
** EPITECH PROJECT, 2020
** create_menu_object.c
** File description:
** create menu object
*/

#include "runner.h"
#include <stdlib.h>

menu_object *create_menu_object(char *path, sfVector2f pos, sfVector2f scale, \
sfIntRect rect)
{
    menu_object *menu_obj = malloc(sizeof(menu_object));

    if (menu_obj == NULL)
        return (NULL);
    menu_obj->sprite = sfSprite_create();
    menu_obj->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(menu_obj->sprite, menu_obj->texture, sfTrue);
    sfSprite_setPosition(menu_obj->sprite, pos);
    sfSprite_setScale(menu_obj->sprite, scale);
    menu_obj->rect = rect;
    menu_obj->pos = pos;
    sfSprite_setTextureRect(menu_obj->sprite, rect);
    return (menu_obj);
}

void destroy_menu_object(menu_object *menu_obj)
{
    sfSprite_destroy(menu_obj->sprite);
    sfTexture_destroy(menu_obj->texture);
    free(menu_obj);
}