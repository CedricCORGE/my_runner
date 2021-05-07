/*
** EPITECH PROJECT, 2020
** score.c
** File description:
** score
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "runner.h"
#include "my.h"

void itc(int nb, char *str)
{
    int i = 0;

    if (nb == 0) {
        str[i] = 48;
        str[i + 1] = '\0';
    } else {
        while (nb > 0) {
            str[i] = nb % 10 + 48;
            nb = nb / 10;
            i++;
        }
        str[i] = '\0';
        my_revstr(str);
    }
}

int update_score(score_t *score, game_object **obj)
{
    score->time = sfClock_getElapsedTime(score->clock);
    score->seconds = score->time.microseconds / 1000000.0;
    if (obj[5]->indic != 0 && obj[6]->indic != 0) {
        if (score->seconds == 1) {
            score->score += 1;
            sfClock_restart(score->clock);
        }
        char *str = malloc(sizeof(char) * 7);
        char *str2 = malloc(sizeof(char) * 100);
        if (str == NULL || str2 == NULL)
            return (1);
        my_strcpy(str, "score: ");
        itc(score->score, str2);
        my_strcat(str, str2);
        sfText_setString(score->text, str);
        sfText_setPosition(score->text, (sfVector2f){10, 0});
        free(str);
        free(str2);
    }
    return (0);
}