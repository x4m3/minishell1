/*
** EPITECH PROJECT, 2018
** source/path
** File description:
** no, real programmers use cat
*/

#include "mysh.h"

void move_path_pointer(char **path)
{
    int i = 0;

    for (; path[0][i] && path[0][i] != '='; i++);
    path[0] += i + 1;
}

char *get_path(char **env)
{
    char *str;

    for (int i = 0; env[i]; i++) {
        if (!str_n_compare(env[i], "PATH=", 5))
            str = str_dup(env[i]);
    }
    return str;
}
