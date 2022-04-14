/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** villager
*/

#include "panoramix.h"
#include <stdio.h>

void print_villager_sentance(villager_sentance_type_t type, int id, int value)
{
    if (type == VILLAGER_START)
        printf("Villager %i: Going into battle!\n", id);
    if (type == VILLAGER_DRINK)
        printf("Villager %i: I need a drink... I see %i servings left.\n", id, value);
    if (type == VILLAGER_FIGHT)
        printf("Villager %i: Take that roman scum! Only %i left.\n", id, value);
    if (type == VILLAGER_REFILL)
        printf("Villager %i: Hey Pano wake up! We need more potion.\n", id);
    if (type == VILLAGER_DONE)
        printf("Villager %i: I'm going to sleep now.\n", id);
    fflush(stdout);
}

void *villager(void *d)
{
    villagers_data_t *data = d;

    print_villager_sentance(VILLAGER_START, data->id, 0);
    return (NULL);
}
