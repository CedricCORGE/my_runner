/*
** EPITECH PROJECT, 2020
** update_menu.c
** File description:
** update menu
*/

#include "my.h"
#include "runner.h"

void update_menu(framebuffer_t *buffer, menu_object **menu, score_t *score, \
game_object **obj)
{
    sfVector2i pos;

    pos = sfMouse_getPositionRenderWindow(buffer->window);
    if (menu[0]->exist == true && menu[9]->exist == false) {
        start_handler(menu, buffer, score, pos);
        exit_handler(buffer, menu, pos);
        setting_handler(buffer, menu, pos);
        fps_handler(menu, buffer, pos);
    } else if (obj[5]->indic == 0 || obj[6]->indic == 0) {
        end_game_handler(obj, buffer, score, pos);
    } else
        pause_handler(menu, buffer, pos);
}