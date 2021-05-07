/*
** EPITECH PROJECT, 2020
** read_map.c
** File description:
** read map
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "runner.h"

int load_text(game_object **obj, char carac, int index, sfVector2f gap);

int add_random_enemy(game_object **obj, int count)
{
    int pos = obj[count - 1]->position.x;
    int rand_x = random_spawn(pos);

    obj[count] = create_object("game_sprite/monstre.png", \
(sfVector2f){rand_x, 613 - 179 * 0.5}, (sfIntRect){0, 0, 248, 203});
    sfSprite_setScale(obj[count]->sprite, (sfVector2f){0.5, 0.5});
    obj[count]->type = OBSTACLE;
    obj[count]->speed = (sfVector2f){-20, 0};
    obj[count]->initial_speed = obj[count]->speed;
    count++;
    sfSprite_setPosition(obj[8]->sprite, \
(sfVector2f){obj[count - 1]->position.x + 677, 613 - 1000 * 0.2});
    obj[8]->initial_pos = (sfVector2f){obj[count - 1]->position.x + 677, \
613 - 1000 * 0.2};
    return (count);
}

int load_all_text(char *map, game_object **obj)
{
    int count = 12;
    int index = 0;
    sfVector2f gap = {0, 0};

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] != '1' && map[i] != ' ' && map[i] != '\n') {
            index = load_text(obj, map[i], index, gap);
            count++;
        }
        if (index == -1)
            return (-1);
        gap.x += 206 * 0.5;
        if (map[i] == '\n') {
            gap.x = 0;
            gap.y += 203 * 0.5;
        }
    }
    count = add_random_enemy(obj, count);
    obj[count] = NULL;
    return (0);
}

int read_map(char *path, game_object **obj)
{
    char *map = malloc(sizeof(char) * 1500);
    FILE *stream;
    size_t size;

    stream = fopen(path, "r");
    if (stream == NULL) {
        free(map);
        return (84);
    }
    size = fread(map, sizeof(char), 1500, stream);
    if (size == -1)
        return (84);
    map[size] = '\0';
    if (load_all_text(map, obj) == -1)
        return (84);
    fclose(stream);
    free(map);
    return (0);
}