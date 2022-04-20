/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** panoramix
*/

#include "panoramix.h"

/**
* @brief It takes the arguments from the command line, checks them, and then
* runs the panoramix function
*
* @param ac the number of arguments passed to the program
* @param av the array of strings passed to the program
*
* @return The return value of the function.
*/
int panoramix(int ac, char **av)
{
    int rvalue = 0;
    int numbers[4];

    rvalue = args_management(ac, av, numbers);
    if (rvalue < 0)
        return (-1);
    rvalue = run_panoramix(numbers);
    if (rvalue < 0)
        return (-1);
    return (0);
}
