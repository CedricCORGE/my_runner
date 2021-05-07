/*
** EPITECH PROJECT, 2020
** print_usage.
** File description:
** print usage
*/

#include "my.h"

void print_usage(void)
{
    my_printf("Finite runner created with CSFML.\n\nUSAGE\n");
    my_printf(" ./my_runner map.txt\n\n\nOPTIONS\n");
    my_printf(" -h         print the usage and quit.\n\n");
    my_printf("USER INTERACTIONS\n SPACE_KEY        jump\n");
    my_printf(" ESCAPE_KEY       pause.\n");
}

void print_error(int ac)
{
    my_printf("./my_runner: bad arguments: %d given but 1 is required\
\nretry with -h\n", ac - 1);
}

int analyse_param(int ac, char **av)
{
    if (ac != 2) {
        print_error(ac);
        return (84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h') {
        print_usage();
        return (0);
    }
    return (1);
}