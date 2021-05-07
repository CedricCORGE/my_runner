/*
** EPITECH PROJECT, 2020
** create_clock.c
** File description:
** create_clock
*/

#include "runner.h"
#include <stdlib.h>

t_clock *create_clock(void)
{
    t_clock *clock = malloc(sizeof(t_clock));

    if (clock == NULL)
        return (NULL);
    clock->clock = sfClock_create();
    clock->clock2 = sfClock_create();
    return (clock);
}

void destroy_clock(t_clock *clock)
{
    sfClock_destroy(clock->clock);
    sfClock_destroy(clock->clock2);
    free(clock);
}