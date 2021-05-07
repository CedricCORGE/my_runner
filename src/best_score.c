/*
** EPITECH PROJECT, 2020
** best_score.c
** File description:
** best score
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int char_to_int(char *str)
{
    int i = 0;
    int nb = 0;

    if (str[i] == '0') {
        nb = 0;
    } else {
        while (str[i]) {
            nb = nb * 10 + str[i] - 48;
            i++;
        }
    }
    return (nb);
}

int check_best_score(int score)
{
    char *best_score = malloc(sizeof(char) * 5);
    FILE *stream = fopen("best_score.txt", "r+");
    FILE *file
    char *char_score = malloc(sizeof(char) * 10);

    if (best_score == NULL || char_score == NULL)
        return (84)
    itc(score, char_score);
    fread(best_score, sizeof(char), 5, stream);
    int best_score2 = char_to_int(best_score);
    if (best_score2 < score) {
        fclose(stream);
        file = fopen("best_score.txt", "w");
        fwrite(char_score, sizeof(char), my_strlen(char_score), file);
        fclose(file);
    } else
        fclose(stream);
    free(char_score);
    free(best_score);
    return (0);
}