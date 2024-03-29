/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** druid
*/

#include "panoramix.h"
#include <stdio.h>

/**
* @brief It prints a message to the screen
*
* @param type The type of sentence to print.
* @param value the number of refills the druid can make
*/
void print_druid_sentence(druid_sentence_type_t type, int value)
{
    char *str = "Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can ";

    if (type == DRUID_START)
        printf("Druid: I'm ready... but sleepy...\n");
    if (type == DRUID_REFILL)
        printf("%sonly make %i more refills after this one.\n", str, value);
    if (type == DRUID_SLEEP)
        printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    fflush(stdout);
}

/**
* @brief The druid waits for the villagers to finish drinking, then refills
* the pot and wakes up the villagers
*
* @param _data pointer to data structure containing all the information needed
* by the druid
*
* @return a pointer to a void.
*/
void *druid(void *_data)
{
    villagers_data_t *data = _data;

    print_druid_sentence(DRUID_START, 0);
    while (data->numbers[NB_REFILLS] > 0) {
        sem_wait(data->need_refill);
        if (data->villagers_status == true) {
            data->numbers[NB_REFILLS]--;
            (*data->nb_pots) = data->numbers[POT_SIZE];
            print_druid_sentence(DRUID_REFILL, data->numbers[NB_REFILLS]);
            sem_post(data->has_refill);
        } else {
            print_druid_sentence(DRUID_SLEEP, 0);
            sem_post(data->has_refill);
            return (NULL);
        }
    }
    print_druid_sentence(DRUID_SLEEP, 0);
    return (NULL);
}
