/*
** EPITECH PROJECT, 2018
** include/mysh
** File description:
** vim-epitech made by x4m3
*/

#ifndef MYSH_H
#define MYSH_H

#include "library.h"
#include "colors.h"

/* prompt.c */
char *prompt_get_input(t_colors *colors, int *status);

/* exec.c */
void check_return(int *status, t_colors *colors);
int exec(char **command, int *status, char **env);

/* path.c */
char *get_path(char **env);

#endif
