/*
** EPITECH PROJECT, 2020
** init_menu.c
** File description:
** init menu
*/

#include "runner.h"
#include "my.h"
#include <stdlib.h>

void create_pause(menu_object **obj)
{
    sfIntRect rect = init_rect(26, 25);

    obj[PAUSE] = create_menu_object("menu/pause_button.png", \
(sfVector2f){1080 - 58, 10}, (sfVector2f){2, 2}, rect);
    rect = init_rect(60, 60);
    obj[UNPAUSE] = create_menu_object("menu/start_button.png", \
(sfVector2f){1080 / 2 - 60, 720 / 2 - 60}, (sfVector2f){2, 2}, rect);
    rect = init_rect(512, 162);
    obj[PAUSE_SPRITE] = create_menu_object("menu/pause_sprite.png", \
(sfVector2f){1080 /2 - 256, 100}, (sfVector2f){1, 1}, rect);
    obj[9]->exist = false;
    obj[PAUSE_SOUND] = create_menu_object("menu/sound.png", \
(sfVector2f){975, 10}, (sfVector2f){0.6, 0.6}, (sfIntRect){20, 18, 141, 80});
}

void create_menu(menu_object **obj)
{
    obj[4] = create_menu_object("menu/fleche.png", (sfVector2f){130, \
10}, (sfVector2f){-2, 2}, (sfIntRect){0, 0, 29, 36});
    obj[SOUND] = create_menu_object("menu/sound.png", (sfVector2f){135, \
18}, (sfVector2f){0.6, 0.6}, (sfIntRect){20, 18, 141, 80});
    obj[FPS] = create_menu_object("menu/fps.png", (sfVector2f){250, \
16}, (sfVector2f){0.6, 0.6}, (sfIntRect){0, 0, 146, 81});
    obj[NBR] = create_menu_object("menu/nbr.png", (sfVector2f){400, \
10}, (sfVector2f){0.2, 0.2}, (sfIntRect){0, 0, 299, 433});
    obj[8] = create_menu_object("menu/fleche.png", (sfVector2f){400, \
10}, (sfVector2f){-2, 2}, (sfIntRect){0, 0, 29, 36});
    obj[3]->exist = false;
    obj[5]->exist = true;
    obj[6]->exist = false;
    obj[0]->exist = true;
    create_pause(obj);
}

menu_object **init_menu(void)
{
    menu_object **obj = malloc(sizeof(menu_object *) * 13);

    if (obj == NULL)
        return (NULL);
    obj[NAME] = create_menu_object("menu/gd_name.png", (sfVector2f){(1080 / 2) \
- 247, 100}, (sfVector2f){1, 1}, (sfIntRect){0, 0, 488, 60});
    obj[PLAY] = create_menu_object("menu/play_button.png", (sfVector2f){(1080 \
/ 2) - 74, 720 / 2 - 72}, (sfVector2f){2, 2}, (sfIntRect){0, 0, 74, 73});
    obj[EXIT] = create_menu_object("menu/exit_button.png", (sfVector2f){(1080 \
- 70), 10}, (sfVector2f){1.68, 1.68}, (sfIntRect){0, 0, 41, 41});
    obj[SETTING] = create_menu_object("menu/setting_button.png", \
(sfVector2f){10, 10}, (sfVector2f){1, 1}, (sfIntRect){0, 0, 69, 68});
    create_menu(obj);
    return (obj);
}

void destroy_menu(menu_object **menu_obj)
{
    for (int i = 0; i < 13; i++) {
        destroy_menu_object(menu_obj[i]);
    }
    free(menu_obj);
}