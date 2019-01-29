/*
** EPITECH PROJECT, 2018
** include/builtins
** File description:
** vim-epitech made by x4m3
*/

#ifndef BUILTINS_H
#define BUILTINS_H

const char *builtins_str[1];
int (*builtins_function[1])(char **);

int list_builtins(void);

int builtins_exit(char **args);

#endif
