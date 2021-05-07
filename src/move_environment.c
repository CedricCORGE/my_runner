/*
** EPITECH PROJECT, 2020
** move_environment.c
** File description:
** move ground and background
*/

#include "runner.h"
#include "my.h"

void reverse_bg(game_object **obj)
{
    sfVector2f scale = {-1, 1};
    sfSprite_setScale(obj[BACKGROUND2_index]->sprite, scale);
    sfSprite_setPosition(obj[BACKGROUND2_index]->sprite, (sfVector2f){2160, 0});
}

void move_rect(menu_object *menu, int left)
{
    menu->rect.top += left;
    sfSprite_setTextureRect(menu->sprite, menu->rect);
}

void move_background(game_object **obj)
{
    sfVector2f pos = {0, 0};
    sfSprite_move(obj[BACKGROUND_index]->sprite, obj[BACKGROUND_index]->speed);
    sfSprite_move(obj[BACKGROUND2_index]->sprite, \
obj[BACKGROUND2_index]->speed);
    pos = sfSprite_getPosition(obj[BACKGROUND_index]->sprite);
    if (pos.x == -1080)
        sfSprite_setPosition(obj[BACKGROUND_index]->sprite, \
(sfVector2f){1080, 0});
    pos = sfSprite_getPosition(obj[BACKGROUND2_index]->sprite);
    if (pos.x == 0)
        sfSprite_setPosition(obj[BACKGROUND2_index]->sprite, \
(sfVector2f){2160, 0});
    pos = sfSprite_getPosition(obj[10]->sprite);
    if (pos.x < 0 - 122 * 1.5)
        sfSprite_setPosition(obj[10]->sprite, (sfVector2f){1100, 100});
    pos = sfSprite_getPosition(obj[11]->sprite);
    if (pos.x < 0 - 122 * 1.5)
        sfSprite_setPosition(obj[11]->sprite, (sfVector2f){1100, 100});
}

void move_ground(game_object **obj)
{
    sfVector2f pos = {0, 0};
    sfSprite_move(obj[GROUND_index]->sprite, obj[GROUND_index]->speed);
    sfSprite_move(obj[GROUND2_index]->sprite, obj[GROUND2_index]->speed);
    pos = sfSprite_getPosition(obj[GROUND_index]->sprite);
    if (pos.x == -1080)
        sfSprite_setPosition(obj[GROUND_index]->sprite, \
(sfVector2f){1080, 613});
    pos = sfSprite_getPosition(obj[GROUND2_index]->sprite);
    if (pos.x == -1080)
        sfSprite_setPosition(obj[GROUND2_index]->sprite, \
(sfVector2f){1080, 613});
}