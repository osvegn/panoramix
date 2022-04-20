/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** test_druid
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "panoramix.h"

Test(print_druid_sentance, test_print_sentance_DRUID_START, .init=cr_redirect_stdout)
{
    print_druid_sentance(DRUID_START, 0);
    cr_assert_stdout_eq_str("Druid: I'm ready... but sleepy...\n");
}

Test(print_druid_sentance, test_print_sentance_DRUID_REFILL, .init=cr_redirect_stdout)
{
    print_druid_sentance(DRUID_REFILL, 10);
    cr_assert_stdout_eq_str("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only make 10 more refills after this one.\n");
}

Test(print_druid_sentance, test_print_sentance_DRUID_SLEEP, .init=cr_redirect_stdout)
{
    print_druid_sentance(DRUID_SLEEP, 0);
    cr_assert_stdout_eq_str("Druid: I'm out of viscum. I'm going back to... zZz\n");
}
