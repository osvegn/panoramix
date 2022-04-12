/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** test_args_management
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "panoramix.h"

Test(args_management, valide_arguments)
{
    int ac = 5;
    char *av[5] = {"./panoramix", "1", "2", "3", "4"};
    int numbers[ARGS_NUMBER];
    int rvalue = 0;

    rvalue = args_management(ac, av, numbers);
    cr_assert_eq(rvalue, 0);
}

Test(args_management, invalide_arguments_numbers, .init=cr_redirect_stdout)
{
    int ac = 3;
    char *av[5] = {"./panoramix", "1", "2", "3", "4"};
    int numbers[ARGS_NUMBER];

    args_management(ac, av, numbers);
    cr_assert_stdout_eq_str("USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>\n");
}

Test(args_management, invalide_arguments)
{
    int ac = 5;
    char *av[5] = {"./panoramix", "-1", "2", "3", "4"};
    int numbers[ARGS_NUMBER];
    int rvalue = 0;

    rvalue = args_management(ac, av, numbers);
    cr_assert_eq(rvalue, -1);
}

Test(args_management, invalide_arguments_three)
{
    int ac = 5;
    char *av[5] = {"./panoramix", "1", "2", "3", "4"};
    int rvalue = 0;

    rvalue = args_management(ac, av, NULL);
    cr_assert_eq(rvalue, -1);
}
