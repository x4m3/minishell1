/*
** EPITECH PROJECT, 2018
** source/builtins/builtins
** File description:
** example of bad code:
*/

#include "builtins.h"

const char *builtins_str[] = {
    "exit",
    "cd",
    "env",
    "setenv",
    "unsetenv",
    "help"
};

int (*builtins_function[]) (char **, char **) = {
    &builtins_exit,
    &builtins_cd,
    &builtins_env,
    &builtins_setenv,
    &builtins_unsetenv,
    &builtins_help
};

int list_builtins(void)
{
    return sizeof(builtins_str) / sizeof(char *);
}
