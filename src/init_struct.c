/*
** EPITECH PROJECT, 2020
** init_struct.c
** File description:
** init struct
*/

#include <stdlib.h>
#include <unistd.h>
#include "runner.h"

void init_background(game_object **obj)
{
    obj[BACKGROUND_index] = create_object("background/background.jpg", \
(sfVector2f){0, 0}, (sfIntRect){0, 0, 1080, 720});
    obj[BACKGROUND2_index] = create_object("background/background.jpg", \
(sfVector2f){1080, 0}, (sfIntRect){0, 0, 1080, 720});
    obj[10] = create_object("background/nuage.png", \
(sfVector2f){1100, 100}, (sfIntRect){0, 0, 122, 58});
    sfSprite_setScale(obj[10]->sprite, (sfVector2f){1.5, 1.5});
    obj[11] = create_object("background/nuage.png", \
(sfVector2f){1762, 100}, (sfIntRect){0, 0, 122, 58});
    sfSprite_setScale(obj[11]->sprite, (sfVector2f){1.5, 1.5});
}

void init_speed(game_object **obj)
{
    obj[BACKGROUND_index]->speed = (sfVector2f){-8, 0};
    obj[BACKGROUND2_index]->speed = (sfVector2f){-8, 0};
    obj[GROUND_index]->speed = (sfVector2f){-20, 0};
    obj[GROUND2_index]->speed = (sfVector2f){-20, 0};
    obj[PLAYER_index]->speed = (sfVector2f){0, 50};
    obj[8]->speed = (sfVector2f){-20, 0};
    obj[10]->speed = (sfVector2f){-13, 0};
    obj[11]->speed = (sfVector2f){-13, 0};
    obj[BACKGROUND_index]->initial_speed = obj[BACKGROUND_index]->speed;
    obj[BACKGROUND2_index]->initial_speed = obj[BACKGROUND2_index]->speed;
    obj[GROUND_index]->initial_speed = obj[GROUND_index]->speed;
    obj[GROUND2_index]->initial_speed = obj[GROUND2_index]->speed;
    obj[PLAYER_index]->initial_speed = (sfVector2f){0, 50};
    obj[8]->initial_speed = obj[8]->speed;
    obj[10]->initial_speed = obj[10]->speed;
    obj[11]->initial_speed = obj[11]->speed;
}

void init_all(game_object **obj)
{
    init_speed(obj);
    obj[BACKGROUND_index]->type = BACKGROUND;
    obj[BACKGROUND2_index]->type = BACKGROUND;
    obj[GROUND_index]->type = GROUND;
    obj[GROUND2_index]->type = GROUND;
    obj[PLAYER_index]->type = PERSO;
    obj[5]->indic = 1;
    obj[6]->indic = 1;
    obj[7]->indic = 1;
    obj[8]->indic = 0;
    obj[8]->type = GROUND;
    obj[9]->indic = 1;
    obj[9]->type = BUTTON;
    obj[10]->type = BACKGROUND;
    obj[11]->type = BACKGROUND;
    reverse_bg(obj);
}

void init_other_object(game_object **obj)
{
    obj[6] = create_object("game_sprite/game_over.png", \
(sfVector2f){1080 / 2 - (820 * 0.7) / 2, 100}, (sfIntRect){0, 0, 820, 394});
    sfSprite_setScale(obj[6]->sprite, (sfVector2f){0.7, 0.7});
    obj[7] = create_object("game_sprite/restart.png", \
(sfVector2f){440, 350}, (sfIntRect){0, 0, 300, 314});
    sfSprite_setScale(obj[7]->sprite, (sfVector2f){0.3, 0.3});
    obj[8] = create_object("game_sprite/end_flag.png", \
(sfVector2f){2200, 613 - 1000 * 0.2}, (sfIntRect){0, 0, 557, 1000});
    sfSprite_setScale(obj[8]->sprite, (sfVector2f){0.2, 0.2});
    obj[9] = create_object("game_sprite/quit.png", \
(sfVector2f){570, 340}, (sfIntRect){0, 0, 310, 310});
    sfSprite_setScale(obj[9]->sprite, (sfVector2f){0.35, 0.35});
    init_background(obj);
    obj[12] = NULL;
    init_all(obj);
}

game_object **init_struct(void)
{
    game_object **obj = malloc(sizeof(game_object) * 50);

    if (obj == NULL)
        return (NULL);
    obj[GROUND_index] = create_object("ground/ground.png", \
(sfVector2f){0, 613}, (sfIntRect){35, 0, 1080, 103});
    obj[GROUND2_index] = create_object("ground/ground.png", \
(sfVector2f){1080, 613}, (sfIntRect){35, 0, 1080, 103});
    obj[PLAYER_index] = create_object("perso/Spritesheet.png", \
(sfVector2f){466, 512}, (sfIntRect){0, 375, 148, 125});
    obj[5] = create_object("game_sprite/level_complete.png", \
(sfVector2f){265, 250}, (sfIntRect){0, 0, 275, 135});
    sfSprite_setScale(obj[5]->sprite, (sfVector2f){2, 2});
    init_other_object(obj);
    return (obj);
}