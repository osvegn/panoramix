/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** run_panoramix
*/

#include "panoramix.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

int run_panoramix(int *numbers)
{
    pthread_t *villagers = NULL;
    data_t *data = NULL;

    villagers = malloc(sizeof(pthread_t) * (numbers[NB_VILLAGERS] + 1));
    data = malloc(sizeof(data_t) * (numbers[NB_VILLAGERS] + 1));
    if (!villagers || !data) {
        fprintf(stderr, "Error: run_panoramix: malloc failed\n");
        return (-1);
    }
    pthread_create(&villagers[0], NULL, &druid, NULL);
    for (int i = 1; i < numbers[NB_VILLAGERS] + 1; i++) {
        data[i].id = i - 1;
        pthread_create(&villagers[i], NULL, &villager, &data[i]);
    }
    for (int i = 1; i < numbers[NB_VILLAGERS] + 1; i++) {
        pthread_join(villagers[i], NULL);
    }
    return (0);
}
