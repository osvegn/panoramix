/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** test_villager
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "panoramix.h"

Test(villager, test_villager_available_with_one_fight, .init=cr_redirect_stdout)
{
    sem_t sem;
    sem_t sem2;
    pthread_mutex_t mut;
    int numbers[4] = {1, 1, 1, 1};
    villagers_data_t *data = init_data(numbers, &sem, &sem2, &mut);

    data[1].id = 0;
    pthread_create(&data[1].thread, NULL, &villager, &data[1]);
    pthread_join(data[1].thread, NULL);
    pthread_mutex_destroy(data->mut);
    sem_destroy(data->need_refill);
    sem_destroy(data->has_refill);
    free(data->nb_pots);
    free(data);
    cr_assert_stdout_eq_str("Villager 0: Going into battle!\nVillager 0: I need a drink... I see 1 servings left.\nVillager 0: Take that roman scum! Only 0 left.\nVillager 0: I'm going to sleep now.\n");
}

Test(villager, test_villager_available_with_multiple_fights, .init=cr_redirect_stdout)
{
    sem_t sem;
    sem_t sem2;
    pthread_mutex_t mut;
    int numbers[4] = {1, 2, 2, 1};
    villagers_data_t *data = init_data(numbers, &sem, &sem2, &mut);

    data[1].id = 0;
    pthread_create(&data[1].thread, NULL, &villager, &data[1]);
    pthread_join(data[1].thread, NULL);
    pthread_mutex_destroy(data->mut);
    sem_destroy(data->need_refill);
    sem_destroy(data->has_refill);
    free(data->nb_pots);
    free(data);
    cr_assert_stdout_eq_str("Villager 0: Going into battle!\nVillager 0: I need a drink... I see 2 servings left.\nVillager 0: Take that roman scum! Only 1 left.\nVillager 0: I need a drink... I see 1 servings left.\nVillager 0: Take that roman scum! Only 0 left.\nVillager 0: I'm going to sleep now.\n");
}