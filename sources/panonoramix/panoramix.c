/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** panoramix
*/

#include "panoramix.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *druid(void *data)
{
    printf("Druid: I'm ready... but sleepy...\n");
    fflush(stdout);
    (void)data;
    return (NULL);
}

void *villager(void *d)
{
    data_t *data = d;

    printf("Villager %i: Going into battle!\n", data->id);
    fflush(stdout);
    (void)data;
    return (NULL);
}

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

int panoramix(int ac, char **av)
{
    int rvalue = 0;
    int numbers[4];

    rvalue = args_management(ac, av, numbers);
    if (rvalue < 0)
        return (-1);
    rvalue = run_panoramix(numbers);
    if (rvalue < 0)
        return (-1);
    return (0);
}
