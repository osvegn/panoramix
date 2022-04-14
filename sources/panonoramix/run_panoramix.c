/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** run_panoramix
*/

#include "panoramix.h"
#include <stdlib.h>
#include <stdio.h>

/**
* @brief It waits for all the villagers to finish their work
*
* @param data the array of villagers
* @param nb_villagers the number of villagers in the village
*/
void wait_for_all_villagers(villagers_data_t *data, int nb_villagers)
{
    int index = 1;

    while (index < nb_villagers + 1) {
        pthread_join(data[index].thread, NULL);
        index++;
    }
}

/**
* @brief It creates the druid thread and the villagers threads
*
* @param data the array of villagers_data_t
* @param nb_villagers the number of villagers to create
*
* @return the value 0.
*/
int start_villagers(villagers_data_t *data, int nb_villagers)
{
    int index = 1;

    pthread_create(&data[0].thread, NULL, &druid, NULL);
    while (index < nb_villagers + 1) {
        data[index].id = index - 1;
        pthread_create(&data[index].thread, NULL, &villager, &data[index]);
        index++;
    }
    return (0);
}

/**
* @brief It creates a number of villagers, each of which will try to drink from the pot
*
* @param numbers an array of integers containing the number of villagers, the
* number of potions, and the number of ingredients.
*
* @return The return value is the number of the pot.
*/
int run_panoramix(int *numbers)
{
    villagers_data_t *data = NULL;
    int nb_pot = numbers[POT_SIZE];

    (void)nb_pot;
    data = malloc(sizeof(villagers_data_t) * (numbers[NB_VILLAGERS] + 1));
    if (!data) {
        fprintf(stderr, "Error: run_panoramix: malloc failed\n");
        return (-1);
    }
    start_villagers(data, numbers[NB_VILLAGERS]);
    wait_for_all_villagers(data, numbers[NB_VILLAGERS]);
    free(data);
    return (0);
}
