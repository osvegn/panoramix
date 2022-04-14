/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** run_panoramix
*/

#include "panoramix.h"
#include <stdlib.h>
#include <stdio.h>

void wait_for_all_villagers(villagers_data_t *data)
{
    int index = 1;

    while (index < data->numbers[NB_VILLAGERS] + 1) {
        pthread_join(data[index].thread, NULL);
        index++;
    }
}

int start_villagers(villagers_data_t *data)
{
    int index = 1;

    pthread_create(&data[0].thread, NULL, &druid, NULL);
    while (index < data->numbers[NB_VILLAGERS] + 1) {
        data[index].id = index - 1;
        pthread_create(&data[index].thread, NULL, &villager, &data[index]);
        index++;
    }
    return (0);
}
void *init_data(int *numbers)
{
    villagers_data_t *data;
    pthread_mutex_t mut;

    data = malloc(sizeof(villagers_data_t) * (numbers[NB_VILLAGERS] + 1));
    if (data == NULL)
        return (NULL);
    pthread_mutex_init(&mut, NULL);
    for (int i = 0; i < numbers[NB_VILLAGERS] + 1; i++) {
        data[i].id = i;
        data[i].mut = &mut;
        data[i].numbers = numbers;
    }
    return (data);
}

int run_panoramix(int *numbers)
{
    villagers_data_t *data = init_data(numbers);

    if (data == NULL)
        return (-1);
    start_villagers(data);
    wait_for_all_villagers(data);
    pthread_mutex_destroy(data->mut);
    free(data);
    return (0);
}
