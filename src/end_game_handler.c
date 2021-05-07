/*
** EPITECH PROJECT, 2020
** end_game_handler.c
** File description:
** end game handler
*/

#include "runner.h"
#include "my.h"

void set_indic(game_object **obj)
{
    obj[PLAYER_index]->indic = 0;
    obj[5]->indic = 1;
    obj[6]->indic = 1;
    obj[7]->indic = 1;
    obj[8]->indic = 0;
    obj[9]->indic = 1;
}

void reset_player(game_object **obj)
{
    obj[PLAYER_index]->jump = 0;
    obj[PLAYER_index]->rect.top = 375;
    obj[PLAYER_index]->rect.left = 0;
    sfSprite_setTextureRect(obj[PLAYER_index]->sprite, obj[PLAYER_index]->rect);
    sfSprite_setPosition(obj[PLAYER_index]->sprite, (sfVector2f){466, 512});
    obj[PLAYER_index]->position = (sfVector2f){466, 512};
}

void restart_game(game_object **obj, framebuffer_t *buffer, score_t *score)
{
    int i = 0;

    for (i = 0; obj[i]; i++) {
        obj[i]->position = obj[i]->initial_pos;
        obj[i]->speed = obj[i]->initial_speed;
        sfSprite_setPosition(obj[i]->sprite, obj[i]->initial_pos);
    }
    add_random_enemy(obj, i - 1);
    set_indic(obj);
    reverse_bg(obj);
    sfMusic_play(buffer->game_music);
    score->score = 0;
    buffer->i = 0;
    reset_player(obj);
    sfSound_stop(buffer->sound);
    sfClock_restart(score->clock);
}

void end_game_handler(game_object **obj, framebuffer_t *buffer, \
score_t *score, sfVector2i pos)
{
    if (pos.x >= obj[7]->position.x && pos.x <= obj[7]->position.x + 300 * 0.3 \
&& pos.y >= obj[7]->position.y && pos.y <= obj[7]->position.y + 314 * 0.3) {
        restart_game(obj, buffer, score);
    }
    if (pos.x >= obj[9]->position.x && pos.x <= obj[9]->position.x + 512 * 0.17\
&& pos.y >= obj[9]->position.y && pos.y <= obj[9]->position.y + 512 * 0.17) {
        sfRenderWindow_close(buffer->window);
    }
}