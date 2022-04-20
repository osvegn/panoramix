/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** run_panoramix
*/

#include "panoramix.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void wait_for_all_villagers(villagers_data_t *data)
{
    int index = 1;

    while (index < data->numbers[NB_VILLAGERS] + 1) {
        pthread_join(data[index].thread, NULL);
        data[index].villagers_status = false;
        index++;
    }
    data[0].villagers_status = false;
    sem_post(data[0].sem);
    pthread_join(data[0].thread, NULL);
}

int start_villagers(villagers_data_t *data)
{
    int index = 1;

    pthread_create(&data[0].thread, NULL, &druid, &data[0]);
    while (index < data->numbers[NB_VILLAGERS] + 1) {
        data[index].id = index - 1;
        pthread_create(&data[index].thread, NULL, &villager, &data[index]);
        index++;
    }
    return (0);
}

void *init_data(int *numbers, sem_t *sem, sem_t *sem2, pthread_mutex_t *mut)
{
    villagers_data_t *data;
    int *nb_pots = NULL;

    nb_pots = malloc(sizeof(int));
    (*nb_pots) = numbers[POT_SIZE];
    data = malloc(sizeof(villagers_data_t) * (numbers[NB_VILLAGERS] + 1));
    if (data == NULL)
        return (NULL);
    pthread_mutex_init(mut, NULL);
    sem_init(sem, 0, 0);
    sem_init(sem2, 0, 0);
    for (int i = 0; i < numbers[NB_VILLAGERS] + 1; i++) {
        data[i].villagers_status = true;
        data[i].sem = sem;
        data[i].sem2 = sem2;
        data[i].nb_pots = nb_pots;
        data[i].id = i;
        data[i].mut = mut;
        data[i].numbers = numbers;
    }
    return (data);
}

int run_panoramix(int *numbers)
{
    sem_t sem;
    sem_t sem2;
    pthread_mutex_t mut;
    villagers_data_t *data = init_data(numbers, &sem, &sem2, &mut);

    if (data == NULL)
        return (-1);
    start_villagers(data);
    wait_for_all_villagers(data);
    pthread_mutex_destroy(data->mut);
    sem_destroy(data->sem);
    sem_destroy(data->sem2);
    free(data);
    return (0);
}
