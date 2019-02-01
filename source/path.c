/*
** EPITECH PROJECT, 2018
** source/path
** File description:
** no, real programmers use cat
*/

#include <stdlib.h> /* for malloc */
#include "mysh.h"

char *full_path_command(char *path, char *command)
{
    char *str = malloc(sizeof(char) * (len_str(path) + len_str(command)));
    int i = 0;

    if (!str)
        return NULL;
    for (; path[i]; i++) {
        str[i] = path[i];
    }
    str[i++] = '/';
    for (int j = 0; command[j]; i++, j++) {
        str[i] = command[j];
    }
    str[i] = '\0';
    return str;
}

char **move_path_pointer(char **path)
{
    int i = 0;

    for (; path[0][i] && path[0][i] != '='; i++);
    path[0] += i + 1;
    return path;
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
