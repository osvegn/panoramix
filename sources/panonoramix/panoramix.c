/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** panoramix
*/

#include "panoramix.h"
#include <stdio.h>

int panoramix(int ac, char **av)
{
    int rvalue = 0;
    int numbers[4];

    rvalue = args_management(ac, av, numbers);
    if (rvalue < 0)
        return (-1);
    return (0);
}
