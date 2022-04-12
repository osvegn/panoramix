/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** villager
*/

#include "panoramix.h"
#include <stdio.h>

void *villager(void *d)
{
    data_t *data = d;

    printf("Villager %i: Going into battle!\n", data->id);
    fflush(stdout);
    (void)data;
    return (NULL);
}
