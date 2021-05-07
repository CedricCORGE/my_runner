/*
** EPITECH PROJECT, 2020
** game.c
** File description:
** game
*/

#include "runner.h"
#include <stdlib.h>
#include "my.h"

int analyse_event(framebuffer_t *buffer, game_object **obj, \
menu_object **menu, score_t *score)
{
    while (sfRenderWindow_pollEvent(buffer->window, &buffer->event)) {
        if (buffer->event.type == sfEvtClosed)
            sfRenderWindow_close(buffer->window);
        if (buffer->event.type == sfEvtKeyPressed && \
buffer->event.key.code == sfKeySpace && obj[5]->indic == 1 && \
obj[6]->indic == 1 && buffer->i == 0) {
            obj[PLAYER_index]->jump += 1;
            return (1);
        }
        if (buffer->event.type == sfEvtMouseButtonPressed)
            update_menu(buffer, menu, score, obj);
        if (buffer->event.type == sfEvtKeyPressed \
&& buffer->event.key.code == sfKeyEscape) {
            escape_pause(menu, buffer);
        }
    }
    if (buffer->i != 0 && buffer->i < 10)
        return (1);
    else
        return (0);
}

void parallax(game_object **obj, sfClock *clock, \
float seconds, sfTime time)
{
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.03) {
        move_background(obj);
        move_ground(obj);
        for (int i = 8; obj[i]; i++) {
            if (!(obj[i]->type == BUTTON)) {
                sfSprite_move(obj[i]->sprite, obj[i]->speed);
                obj[i]->position.x += obj[i]->speed.x;
            }
        }
        sfClock_restart(clock);
    }
}

void game(t_clock *clock, game_object **obj, framebuffer_t *buffer, int indic)
{
    parallax(obj, clock->clock, clock->seconds, clock->time);
    if (indic == 1) {
        clock->time2 = sfClock_getElapsedTime(clock->clock2);
        clock->seconds2 = clock->time2.microseconds / 1000000.0;
        buffer->i = jump(obj, clock->clock2, buffer->i, \
        clock->seconds2);
    }
}

int start_game(framebuffer_t *buffer, game_object **obj, \
t_clock *clock, score_t *score)
{
    int indic = 0;
    menu_object **menu = init_menu();

    if (menu == NULL)
        return (84);
    while (sfRenderWindow_isOpen(buffer->window)) {
        indic = analyse_event(buffer, obj, menu, score);
        sfRenderWindow_clear(buffer->window, sfBlack);
        if (menu[0]->exist == false) {
            game(clock, obj, buffer, indic);
            check_collision(obj, buffer);
            check_end_game(obj, buffer);
            if (update_score(score, obj) == 1)
                return (84);
        }
        gameobject_draw(obj, buffer, score->text, menu);
    }
    destroy_menu(menu);
    return (0);
}

int display_window(framebuffer_t *buffer, game_object **obj, char *path)
{
    t_clock *clock = create_clock();
    score_t *score = init_score();

    if (clock == NULL || score == NULL)
        return (84);
    if (read_map(path, obj) == 84) {
        destroy_buffer(buffer);
        destroy_clock(clock);
        destroy_score(score);
        destroy_all(obj);
        return (84);
    }
    if (start_game(buffer, obj, clock, score) == 84)
        return (84);
    destroy_clock(clock);
    destroy_score(score);
    return (0);
}