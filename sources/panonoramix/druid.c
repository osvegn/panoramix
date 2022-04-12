/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** druid
*/

#include "panoramix.h"
#include <stdio.h>

void *druid(void *data)
{
    printf("Druid: I'm ready... but sleepy...\n");
    fflush(stdout);
    (void)data;
    return (NULL);
}
