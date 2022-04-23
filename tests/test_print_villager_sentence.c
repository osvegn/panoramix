/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** test_print_villager_sentence
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "panoramix.h"

Test(print_villager_sentence, valide_sentence_start, .init=cr_redirect_stdout)
{
    print_villager_sentence(VILLAGER_START, 1, 0);
    cr_assert_stdout_eq_str("Villager 1: Going into battle!\n");
}

Test(print_villager_sentence, valide_sentence_done, .init=cr_redirect_stdout)
{
    print_villager_sentence(VILLAGER_DONE, 1, 0);
    cr_assert_stdout_eq_str("Villager 1: I'm going to sleep now.\n");
}

Test(print_villager_sentence, valide_sentence_fight, .init=cr_redirect_stdout)
{
    print_villager_sentence(VILLAGER_FIGHT, 10, 5);
    cr_assert_stdout_eq_str("Villager 10: Take that roman scum! Only 5 left.\n");
}

Test(print_villager_sentence, valide_sentence_refill, .init=cr_redirect_stdout)
{
    print_villager_sentence(VILLAGER_REFILL, 8, 253);
    cr_assert_stdout_eq_str("Villager 8: Hey Pano wake up! We need more potion.\n");
}

Test(print_villager_sentence, valide_sentence_drink, .init=cr_redirect_stdout)
{
    print_villager_sentence(VILLAGER_DRINK, 16, 523);
    cr_assert_stdout_eq_str("Villager 16: I need a drink... I see 523 servings left.\n");
}
