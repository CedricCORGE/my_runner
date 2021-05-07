/*
** EPITECH PROJECT, 2020
** display.c
** File description:
** display
*/

#include "runner.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "my.h"

void update_rect(game_object *obj)
{
    if (obj->jump == 2) {
        obj->rect.top -= 125;
    }
    if (obj->jump == 3) {
        obj->rect.top -= 125;
    }
    if (obj->jump == 4) {
        obj->rect.top -= 125;
    }
    if (obj->jump > 4) {
        obj->rect.top = 375;
        obj->jump = 1;
    }
}

int draw_jump(game_object *obj, int offset, int move)
{
    sfVector2f pos = sfSprite_getPosition(obj->sprite);
    sfVector2f pos2 = {0, 0};
    pos2.x = pos.x;
    if (obj->indic < 5)
        pos2.y += pos.y - obj->speed.y;
    else
        pos2.y += pos.y + obj->speed.y;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    obj->rect.left += move;
    if (obj->rect.left == offset) {
        obj->rect.left = 0;
    }
    obj->position = pos2;
    sfSprite_setPosition(obj->sprite, pos2);
    return (0);
}

int jump(game_object **obj, sfClock *clock, int i, float seconds)
{
    if (seconds > 0.04 && i < 10) {
        if (obj[PLAYER_index]->indic == 0)
            update_rect(obj[PLAYER_index]);
        draw_jump(obj[PLAYER_index], 1480, 148);
        sfClock_restart(clock);
        i++;
        obj[PLAYER_index]->indic++;
        if (i == 10) {
            i = 0;
            obj[PLAYER_index]->indic = 0;
        }
    }
    return (i);
}

void menuobject_draw(menu_object **menu, sfRenderWindow *window)
{
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawSprite(window, menu[i]->sprite, NULL);
    }
    if (menu[3]->exist == true) {
        sfRenderWindow_drawSprite(window, menu[4]->sprite, NULL);
        sfRenderWindow_drawSprite(window, menu[5]->sprite, NULL);
        sfRenderWindow_drawSprite(window, menu[6]->sprite, NULL);
        if (menu[6]->exist == true) {
            sfRenderWindow_drawSprite(window, menu[8]->sprite, NULL);
            sfRenderWindow_drawSprite(window, menu[7]->sprite, NULL);
        }
    }
}

void gameobject_draw(game_object **obj, framebuffer_t *buffer, \
sfText *text, menu_object **menu)
{
    for (int i = 0; obj[i]; i++) {
        if (!(obj[i]->indic == 1)) {
            sfRenderWindow_drawSprite(buffer->window, obj[i]->sprite, NULL);
        }
    }
    if (menu[0]->exist == false && menu[9]->exist == false)
        sfRenderWindow_drawSprite(buffer->window, menu[9]->sprite, NULL);
    else if (menu[9]->exist == true)
        display_pause(buffer->window, menu);
    if (menu[0]->exist == true && menu[9]->exist == false)
            menuobject_draw(menu, buffer->window);
    sfRenderWindow_drawText(buffer->window, text, NULL);
    sfRenderWindow_display(buffer->window);
}