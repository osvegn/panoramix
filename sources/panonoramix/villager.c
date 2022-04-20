/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** villager
*/

#include "panoramix.h"
#include <stdio.h>
#include <unistd.h>

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
    int nb_fight = data->numbers[NB_FIGHTS];

    print_villager_sentance(VILLAGER_START, data->id, 0);
    while (nb_fight > 0) {
        pthread_mutex_lock(data->mut);
        if (data->numbers[NB_REFILLS] <= 0) {
            pthread_mutex_unlock(data->mut);
            return (NULL);
        }
        if ((*data->nb_pots) > 0) {
            print_villager_sentance(VILLAGER_DRINK, data->id, (*data->nb_pots));
            (*data->nb_pots)--;
            nb_fight--;
            print_villager_sentance(VILLAGER_FIGHT, data->id, nb_fight);
        } else {
            print_villager_sentance(VILLAGER_REFILL, data->id, 0);
            sem_post(data->sem);
            sem_wait(data->sem2);
        }
        pthread_mutex_unlock(data->mut);
    }
    print_villager_sentance(VILLAGER_DONE, data->id, 0);
    return (NULL);
}
