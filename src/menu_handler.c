/*
** EPITECH PROJECT, 2020
** menu_handler.c
** File description:
** menu handler
*/

#include "my.h"
#include "runner.h"

void start_handler(menu_object **menu, framebuffer_t *buffer, \
score_t *score, sfVector2i pos)
{
    if (pos.x >= menu[1]->pos.x && pos.x <= (menu[1]->pos.x + 74 * 2) && \
pos.y >= menu[1]->pos.y && pos.y <= (menu[1]->pos.y + 72 * 2)) {
        menu[0]->exist = 0;
        sfClock_restart(score->clock);
        sfMusic_stop(buffer->menu_music);
        sfMusic_play(buffer->game_music);
    }
}

void setting(menu_object **menu, framebuffer_t *buffer, \
sfVector2i pos)
{
    if (pos.x >= menu[5]->pos.x && pos.x <= (menu[5]->pos.x + 225) * 0.6 && \
pos.y >= menu[5]->pos.y && pos.y <= (menu[5]->pos.y + 100) * 0.6) {
        if (menu[5]->exist == true) {
            sfMusic_setVolume(buffer->menu_music, 0);
            sfMusic_setVolume(buffer->game_music, 0);
            move_rect(menu[5], 110);
            move_rect(menu[12], 110);
            menu[5]->exist = false;
        } else {
            sfMusic_setVolume(buffer->menu_music, 100);
            sfMusic_setVolume(buffer->game_music, 100);
            move_rect(menu[5], -110);
            move_rect(menu[12], -110);
            menu[5]->exist = true;
        }
    }
}

void setting_handler(framebuffer_t *buffer, menu_object **menu, sfVector2i pos)
{
    if ((pos.x >= menu[3]->pos.x && pos.x <= menu[3]->pos.x + 69 && \
pos.y >= menu[3]->pos.y && pos.y <= menu[3]->pos.y + 68) && \
menu[3]->exist == true) {
        menu[3]->exist = false;
        menu[6]->exist = false;
    } else if ((pos.x >= menu[3]->pos.x && pos.x <= menu[3]->pos.x + 69 && \
pos.y >= menu[3]->pos.y && pos.y <= menu[3]->pos.x + 68) || \
menu[3]->exist == true) {
        setting(menu, buffer, pos);
        menu[3]->exist = true;
    }
}

void exit_handler(framebuffer_t *buffer, menu_object **menu, sfVector2i pos)
{
    if (pos.x >= menu[2]->pos.x && pos.x <= (menu[2]->pos.x + 41 * 1.68) && \
pos.y >= menu[2]->pos.y && pos.y <= (menu[2]->pos.y + 41 * 1.68))
        sfRenderWindow_close(buffer->window);
}