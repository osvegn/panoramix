/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** print_usage
*/

#include <stdio.h>

void print_usage(char *name)
{
    printf("USAGE: %s <nb_villagers> <pot_size> <nb_fights> <nb_refills>\n", name);
    fflush(stdout);
}
