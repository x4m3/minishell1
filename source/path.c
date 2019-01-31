/*
** EPITECH PROJECT, 2018
** source/path
** File description:
** no, real programmers use cat
*/

#include "mysh.h"

void get_path(char **env)
{
    for (int i = 0; env[i]; i++) {
        if (!str_compare(env[i], "PATH="))
            putput("%s", env[i]);
    }
}
