/*
** EPITECH PROJECT, 2020
** random_spawn.c
** File description:
** randow spawn
*/

#include <time.h>
#include <stdlib.h>
#include "my.h"

int random_spawn(int pos)
{
    int rand_nbr = 0;

    srand(time(NULL));
    rand_nbr = rand() % 500;
    rand_nbr += (pos + 500);
    return (rand_nbr);
}