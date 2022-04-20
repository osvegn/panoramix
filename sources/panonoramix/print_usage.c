/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** print_usage
*/

#include <stdio.h>

/**
* @brief It prints the usage of the program
*
* @param name the name of the program
*/
void print_usage(char *name)
{
    char *s = "USAGE: %s <nb_villagers> <pot_size> <nb_fights> <nb_refills>\n";

    fprintf(stderr, s, name);
    fflush(stderr);
}
