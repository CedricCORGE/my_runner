/*
** EPITECH PROJECT, 2021
** infinite.c
** File description:
** infinite mode
*/

#include "my.h"
#include "runner.h"

int infinite_mode(game_object **obj, framebuffer_t *buffer, \
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
            infin_game(clock, obj, buffer, indic);
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

int start_infinite(game_object **obj, framebuffer_t *buffer)
{
    t_clock *clock = create_clock();
    score_t *score = init_score();

    if (clock == NULL || score == NULL)
        return (84);
    if (infinite_mode(obj, buffer, clock, score) == 84)
        return (84);
    destroy_clock(clock);
    destroy_score(score);
    return (0);
}