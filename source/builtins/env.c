/*
** EPITECH PROJECT, 2018
** source/builtins/env
** File description:
** xkcd.com/378
*/

#include "library.h"
#include "builtins.h"

int builtins_env(char **args, char **env)
{
    for (int i = 0; env[i]; i++)
        putput("%s\n", env[i]);
    return 0;
}
