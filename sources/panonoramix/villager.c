/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** villager
*/

#include "panoramix.h"
#include <stdio.h>
#include <unistd.h>

/**
* @brief It prints a message to the screen
*
* @param type The type of sentance the villager is saying.
* @param id The id of the villager.
* @param value The value of the sentance.
*/
void print_villager_sentance(villager_sentance_type_t type, int id, int value)
{
    printf("Villager %i: ", id);
    if (type == VILLAGER_START)
        printf("Going into battle!\n");
    if (type == VILLAGER_DRINK)
        printf("I need a drink... I see %i servings left.\n", value);
    if (type == VILLAGER_FIGHT)
        printf("Take that roman scum! Only %i left.\n", value);
    if (type == VILLAGER_REFILL)
        printf("Hey Pano wake up! We need more potion.\n");
    if (type == VILLAGER_DONE)
        printf("I'm going to sleep now.\n");
    fflush(stdout);
}

/**
* @brief It checks if there are any pots left, if there are, it decrements
* the number of pots and the number of fights, and prints a message. If there
* are no pots left, it prints a message and waits for the druid to
* refill the pots
*
* @param data a pointer to a structure containing all the data needed by the
* thread
* @param nb_fight the number of fights left
*/
void villager_action(villagers_data_t *data, int *nb_fight)
{
    if ((*data->nb_pots) > 0) {
        print_villager_sentance(VILLAGER_DRINK, data->id, (*data->nb_pots));
        (*data->nb_pots)--;
        (*nb_fight)--;
        print_villager_sentance(VILLAGER_FIGHT, data->id, *nb_fight);
    } else {
        print_villager_sentance(VILLAGER_REFILL, data->id, 0);
        sem_post(data->sem);
        sem_wait(data->sem2);
    }
}

/**
* @brief It's a loop that locks the mutex, checks if the number of refills
* is greater than 0, then does some stuff, then unlocks the mutex
*
* @param _data the data passed to the thread
*
* @return a pointer to a void.
*/
void *villager(void *_data)
{
    villagers_data_t *data = _data;
    int nb_fight = data->numbers[NB_FIGHTS];

    print_villager_sentance(VILLAGER_START, data->id, 0);
    while (nb_fight > 0) {
        pthread_mutex_lock(data->mut);
        if (data->numbers[NB_REFILLS] <= 0) {
            pthread_mutex_unlock(data->mut);
            return (NULL);
        }
        villager_action(data, &nb_fight);
        pthread_mutex_unlock(data->mut);
    }
    print_villager_sentance(VILLAGER_DONE, data->id, 0);
    return (NULL);
}
