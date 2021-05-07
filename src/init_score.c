/*
** EPITECH PROJECT, 2020
** init_score.c
** File description:
** init score
*/

#include "runner.h"
#include <stdlib.h>

score_t *init_score(void)
{
    score_t *score = malloc(sizeof(score_t));

    if (score == NULL)
        return (NULL);
    score->text = sfText_create();
    score->font = sfFont_createFromFile("arial.ttf");
    sfText_setFont(score->text, score->font);
    score->score = 0;
    score->seconds = 0;
    score->clock = sfClock_create();
    return (score);
}

void destroy_score(score_t *score)
{
    sfText_destroy(score->text);
    sfFont_destroy(score->font);
    sfClock_destroy(score->clock);
    free(score);
}