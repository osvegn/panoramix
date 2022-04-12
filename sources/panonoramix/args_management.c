/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** args_management
*/

#include "panoramix.h"
#include <stdlib.h>
#include <stdio.h>

/**
* @brief It checks if the number of arguments is correct, and if so, it
* converts them to
* integers and stores them in the array pointed to by `number`
*
* @param ac the number of arguments passed to the program
* @param av the array of arguments
* @param number the array of integers that will be filled with the arguments
*
* @return 0 if the arguments are valid, 1 if the number of
* arguments is invalid and -1 if the arguments are not valid.
*/
int args_management(int ac, char **av, int *number)
{
    int rvalue = 0;

    if (number == NULL)
        return (-1);
    if (ac != ARGS_NUMBER + 1) {
        print_usage(av[0]);
        return (1);
    }
    for (int i = 0; i < 4; i++) {
        rvalue = atoi(av[i + 1]);
        if (rvalue <= 0) {
            fprintf(stderr, "Values must be an integer >0.\n");
            return (-1);
        }
        number[i] = rvalue;
    }
    return (0);
}
