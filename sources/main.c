/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** main
*/

#include "panoramix.h"

int main(int ac, char **av)
{
    int rvalue = 0;

    rvalue = panoramix(ac, av);
    if (rvalue < 0)
        return (EXIT_ERROR);
    return (EXIT_SUCCESS);
}
