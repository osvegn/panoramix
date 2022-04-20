/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** test_druid
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "panoramix.h"

Test(print_druid_sentance, test_print_sentance_DRUID_START, .init=cr_redirect_stdout)
{
    print_druid_sentance(DRUID_START, 0);
    cr_assert_stdout_eq_str("Druid: I'm ready... but sleepy...\n");
}

Test(print_druid_sentance, test_print_sentance_DRUID_REFILL, .init=cr_redirect_stdout)
{
    print_druid_sentance(DRUID_REFILL, 10);
    cr_assert_stdout_eq_str("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only make 10 more refills after this one.\n");
}

Test(print_druid_sentance, test_print_sentance_DRUID_SLEEP, .init=cr_redirect_stdout)
{
    print_druid_sentance(DRUID_SLEEP, 0);
    cr_assert_stdout_eq_str("Druid: I'm out of viscum. I'm going back to... zZz\n");
}

Test(druid, test_druid_available_without_refill, .init=cr_redirect_stdout)
{
    sem_t sem;
    sem_t sem2;
    pthread_mutex_t mut;
    int numbers[4] = {2, 2, 2, 2};
    villagers_data_t *data = init_data(numbers, &sem, &sem2, &mut);

    pthread_create(&data[0].thread, NULL, &druid, &data[0]);
    data[0].villagers_status = false;
    sem_post(&sem);
    pthread_join(data[0].thread, NULL);
    pthread_mutex_destroy(data->mut);
    sem_destroy(data->sem);
    sem_destroy(data->sem2);
    free(data->nb_pots);
    free(data);
    cr_assert_stdout_eq_str("Druid: I'm ready... but sleepy...\nDruid: I'm out of viscum. I'm going back to... zZz\n");
}

Test(druid, test_druid_available_with_refill, .init=cr_redirect_stdout)
{
    sem_t sem;
    sem_t sem2;
    pthread_mutex_t mut;
    int numbers[4] = {2, 2, 2, 1};
    villagers_data_t *data = init_data(numbers, &sem, &sem2, &mut);

    pthread_create(&data[0].thread, NULL, &druid, &data[0]);
    sem_post(&sem);
    pthread_join(data[0].thread, NULL);
    pthread_mutex_destroy(data->mut);
    sem_destroy(data->sem);
    sem_destroy(data->sem2);
    free(data->nb_pots);
    free(data);
    cr_assert_stdout_eq_str("Druid: I'm ready... but sleepy...\nDruid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only make 0 more refills after this one.\nDruid: I'm out of viscum. I'm going back to... zZz\n");
}