/*
** EPITECH PROJECT, 2020
** pause_menu.c
** File description:
** pause menu
*/

#include "runner.h"
#include "my.h"

void escape_pause(menu_object **menu, framebuffer_t *buffer)
{
    if (menu[PAUSE]->exist == false && menu[NAME]->exist == false) {
        menu[PAUSE]->exist = true;
        menu[NAME]->exist = true;
        sfMusic_pause(buffer->game_music);
    } else if (menu[PAUSE]->exist == true) {
        menu[PAUSE]->exist = false;
        menu[NAME]->exist = false;
        sfMusic_play(buffer->game_music);
    }
}

void display_pause(sfRenderWindow *window, menu_object **menu)
{
    sfRenderWindow_drawSprite(window, menu[10]->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu[11]->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu[12]->sprite, NULL);
}

void pause_sound(menu_object **menu, framebuffer_t *buffer, sfVector2i pos)
{
    if (menu[PAUSE]->exist == true && pos.x >= menu[12]->pos.x && \
pos.x <= menu[12]->pos.x + 157 * 0.6 && pos.y >= menu[12]->pos.y && \
pos.y <= menu[12]->pos.y + 100 * 0.6) {
        if (menu[5]->exist == true) {
            sfMusic_setVolume(buffer->menu_music, 0);
            sfMusic_setVolume(buffer->game_music, 0);
            move_rect(menu[12], 110);
            menu[5]->exist = false;
        } else {
            sfMusic_setVolume(buffer->menu_music, 100);
            sfMusic_setVolume(buffer->game_music, 100);
            move_rect(menu[12], -110);
            menu[5]->exist = true;
        }
    }
}

void pause_handler(menu_object **menu, framebuffer_t *buffer, sfVector2i pos)
{
    pause_sound(menu, buffer, pos);
    if (pos.x >= menu[9]->pos.x && pos.x <= menu[9]->pos.x + 25 * 2 \
&& pos.y >= menu[9]->pos.y && pos.y <= menu[9]->pos.y + 25 * 2) {
        menu[9]->exist = true;
        menu[0]->exist = true;
        sfMusic_pause(buffer->game_music);
    } else if (menu[9]->exist == true && pos.x >= menu[10]->pos.x && \
pos.x <= menu[10]->pos.x + 58 * 2 && \
pos.y >= menu[10]->pos.y && pos.y <= menu[10]->pos.y + 58 * 2) {
        menu[9]->exist = false;
        menu[0]->exist = false;
        sfMusic_play(buffer->game_music);
    }
}