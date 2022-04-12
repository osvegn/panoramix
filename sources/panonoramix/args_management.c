/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** args_management
*/

#include "panoramix.h"
#include <stdlib.h>

int args_management(int ac, char **av, int *number)
{
    int rvalue = 0;

    if (number == NULL)
        return (-1);
    if (ac != ARGS_NUMBER + 1) {
        print_usage(av[0]);
        return (0);
    }
    for (int i = 0; i < 4; i++) {
        rvalue = atoi(av[i + 1]);
        if (rvalue <= 0) {
            return (-1);
        }
        number[i] = rvalue;
    }
    return (0);
}
