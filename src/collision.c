/*
** EPITECH PROJECT, 2020
** collision.c
** File description:
** check_collision
*/

#include "runner.h"
#include "my.h"

void game_fail(game_object **obj, framebuffer_t *buffer)
{
    if (obj[6]->indic == 1 && obj[7]->indic == 1 && obj[9]->indic == 1)
                set_sound(buffer->sound, buffer->sound_buffer_l);
    sfRenderWindow_drawSprite(buffer->window, obj[6]->sprite, NULL);
    obj[6]->indic = 0;
    obj[7]->indic = 0;
    obj[9]->indic = 0;
    stop_game(obj, buffer);
}

void check_collision_rand(game_object **obj, framebuffer_t *buffer, int i)
{
    if (obj[PLAYER_index]->position.x + 113 >= obj[i]->position.x + 25 && \
obj[PLAYER_index]->position.x + 36 <= obj[i]->position.x + 203 * 0.5 && \
obj[PLAYER_index]->position.y + 101 >= obj[i]->position.y) {
        game_fail(obj, buffer);
    }
}

void check_spike_collision(game_object **obj, framebuffer_t *buffer, int i)
{
    if (obj[4]->position.x + 113 >= obj[i]->position.x + 29 * 0.5 && \
obj[PLAYER_index]->position.x + 36 <= obj[i]->position.x + 181 * 0.5 && \
obj[PLAYER_index]->position.y + 101 >= obj[i]->position.y + 151 * 0.5 && \
obj[i]->type == OBSTACLE) {
        game_fail(obj, buffer);
    }
    if (obj[4]->position.x + 113 >= obj[i]->position.x + 92 * 0.5 && \
obj[PLAYER_index]->position.x + 36 <= obj[i]->position.x + 117 * 0.5 && \
obj[PLAYER_index]->position.y + 101 >= obj[i]->position.y + 25 * 0.5 && \
obj[i]->type == OBSTACLE) {
        game_fail(obj, buffer);
    }
}

void check_collision(game_object **obj, framebuffer_t *buffer)
{
    int i = 0;

    for (i = 12; obj[i]; i++) {
        check_spike_collision(obj, buffer, i);
    }
    check_collision_rand(obj, buffer, i - 1);
}