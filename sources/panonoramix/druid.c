/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** druid
*/

#include "panoramix.h"
#include <stdio.h>

void print_druid_sentance(druid_sentance_type_t type, int value)
{
    char *str = "Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can ";

    if (type == DRUID_START)
        printf("Druid: I'm ready... but sleepy...\n");
    if (type == DRUID_REFILL)
        printf("%sonly make %i more refills after this one.\n", value, str);
    if (type == DRUID_SLEEP)
        printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    fflush(stdout);
}

void *druid(void *d)
{
    villagers_data_t *data = d;

    print_druid_sentance(DRUID_START, 0);
    while (data->numbers[NB_REFILLS] > 0) {
        sem_wait(data->sem);
        if (data->villagers_status == true) {
            data->numbers[NB_REFILLS]--;
            (*data->nb_pots) = data->numbers[POT_SIZE];
            print_druid_sentance(DRUID_REFILL, data->numbers[NB_REFILLS]);
            sem_post(data->sem2);
        } else {
            print_druid_sentance(DRUID_SLEEP, 0);
            sem_post(data->sem2);
            return (NULL);
        }
    }
    print_druid_sentance(DRUID_SLEEP, 0);
    return (NULL);
}
