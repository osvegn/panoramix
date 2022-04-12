/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** panoramix
*/

#pragma once

#define EXIT_SUCCESS 0
#define EXIT_ERROR 84

#define ARGS_NUMBER 4

void print_usage(char *name);
int args_management(int ac, char **av, int *number);
int panoramix(int ac, char **av);
