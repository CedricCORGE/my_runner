/*
** EPITECH PROJECT, 2020
** fps_handler.c
** File description:
** fps handler
*/

#include "runner.h"
#include "my.h"

void set_fps_limit(framebuffer_t *buffer, menu_object **menu, sfVector2i pos)
{
    if (pos.x >= menu[7]->pos.x + 43 * 0.2 && pos.x <= menu[7]->pos.x + \
233 * 0.2 && pos.y >= menu[7]->pos.y && pos.y <= menu[7]->pos.y + 135 * 0.2) {
        sfRenderWindow_setFramerateLimit(buffer->window, 30);
    }
    if (pos.x >= menu[7]->pos.x + 52 * 0.2 && pos.x <= menu[7]->pos.x + 243 \
* 0.2 && pos.y >= menu[7]->pos.y + 135 * 0.2 && \
pos.y <= menu[7]->pos.y + 271 * 0.2) {
        sfRenderWindow_setFramerateLimit(buffer->window, 60);
    }
    if (pos.x >= menu[7]->pos.x + 13 * 0.2 && pos.x <= menu[7]->pos.x + 289 \
* 0.2 && pos.y >= menu[7]->pos.y + 271 * 0.2 && \
pos.y <= menu[7]->pos.y + 415 * 0.2) {
        sfRenderWindow_setFramerateLimit(buffer->window, 120);
    }
}

void fps_handler(menu_object **menu, framebuffer_t *buffer, sfVector2i pos)
{
    if ((pos.x >= menu[6]->pos.x && pos.x <= menu[6]->pos.x + 146 * 0.6 && \
pos.y >= menu[6]->pos.y && pos.y <= menu[6]->pos.y + 81 * 0.6) && \
(menu[6]->exist == true)) {
        menu[6]->exist = false;
    } else if ((pos.x >= menu[6]->pos.x && pos.x <= menu[6]->pos.x + 146 \
*0.6 && pos.y >= menu[6]->pos.y && pos.y <= menu[6]->pos.y + 81 * 0.6) || \
(menu[6]->exist == true)) {
        menu[6]->exist = true;
        set_fps_limit(buffer, menu, pos);
    }
}