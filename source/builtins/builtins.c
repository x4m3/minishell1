/*
** EPITECH PROJECT, 2018
** source/builtins/builtins
** File description:
** example of bad code:
*/

#include "builtins.h"

const char *builtins_str[1] = {
    "exit"
};

int (*builtins_function[1]) (char **) = {
    &builtins_exit
};

int list_builtins(void)
{
    return sizeof(builtins_str) / sizeof(char *);
}

void builtins(void)
{
}
