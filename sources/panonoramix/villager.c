/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** villager
*/

#include "panoramix.h"
#include <stdio.h>
#include <unistd.h>

static const char *sentences[5] = {
    "Villager %i: Going into battle!\n",
    "Villager %i: I need a drink... I see %i servings left.\n",
    "Villager %i: Hey Pano wake up! We need more potion.\n",
    "Villager %i: Take that roman scum! Only %i left.\n",
    "Villager %i: I'm going to sleep now.\n"
};

/**
* @brief It prints a message to the screen
*
* @param type The type of sentence the villager is saying.
* @param id The id of the villager.
* @param value The value of the sentence.
*/
void print_villager_sentence(villager_sentence_type_t type, int id, int value)
{
    switch (type)
    {
    case VILLAGER_START:
        printf(sentences[type], id);
        break;
    case VILLAGER_DRINK:
        printf(sentences[type], id, value);
        break;
    case VILLAGER_REFILL:
        printf(sentences[type], id);
        break;
    case VILLAGER_FIGHT:
        printf(sentences[type], id, value);
        break;
    case VILLAGER_DONE:
        printf(sentences[type], id);
        break;
    }
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
        print_villager_sentence(VILLAGER_DRINK, data->id, (*data->nb_pots));
        (*data->nb_pots)--;
        (*nb_fight)--;
        print_villager_sentence(VILLAGER_FIGHT, data->id, *nb_fight);
    } else {
        print_villager_sentence(VILLAGER_REFILL, data->id, 0);
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

    print_villager_sentence(VILLAGER_START, data->id, 0);
    while (nb_fight > 0) {
        pthread_mutex_lock(data->mut);
        if (data->numbers[NB_REFILLS] <= 0) {
            pthread_mutex_unlock(data->mut);
            return (NULL);
        }
        villager_action(data, &nb_fight);
        pthread_mutex_unlock(data->mut);
    }
    print_villager_sentence(VILLAGER_DONE, data->id, 0);
    return (NULL);
}
