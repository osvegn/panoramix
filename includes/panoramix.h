/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** panoramix
*/

#pragma once

#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>

#define EXIT_SUCCESS 0
#define EXIT_ERROR 84
#define ARGS_NUMBER 4

typedef enum druid_sentence_type_e {
    DRUID_START,
    DRUID_REFILL,
    DRUID_SLEEP,
} druid_sentence_type_t;

typedef enum villager_sentence_type_e {
    VILLAGER_START,
    VILLAGER_DRINK,
    VILLAGER_REFILL,
    VILLAGER_FIGHT,
    VILLAGER_DONE,
} villager_sentence_type_t;

typedef enum args_type_e {
    NB_VILLAGERS,
    POT_SIZE,
    NB_FIGHTS,
    NB_REFILLS
} args_type_t;

typedef struct villagers_data_s {
    pthread_t thread;
    int id;
    pthread_mutex_t *mut;
    sem_t *sem;
    sem_t *sem2;
    bool villagers_status;
    int *numbers;
    int *nb_pots;
} villagers_data_t;

void print_usage(char *name);
int args_management(int ac, char **av, int *number);
int panoramix(int ac, char **av);
int run_panoramix(int *numbers);
void *villager(void *d);
void *druid(void *data);
void print_villager_sentence(villager_sentence_type_t type, int id, int value);
void print_druid_sentence(druid_sentence_type_t type, int value);
void *init_data(int *numbers, sem_t *sem, sem_t *sem2, pthread_mutex_t *mut);
