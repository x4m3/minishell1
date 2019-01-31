/*
** EPITECH PROJECT, 2018
** source/path
** File description:
** no, real programmers use cat
*/

#include "mysh.h"

char *get_path(char **env)
{
    char *str;

    for (int i = 0; env[i]; i++) {
        if (!str_n_compare(env[i], "PATH=", 5))
            str = str_dup(env[i]);
    }
    return str;
}
