/*
** EPITECH PROJECT, 2018
** include/builtins
** File description:
** vim-epitech made by x4m3
*/

#ifndef BUILTINS_H
#define BUILTINS_H

const char *builtins_str[6];
int (*builtins_function[6])(char **, char **);

int list_builtins(void);

int builtins_exit(char **args, char **env);
int builtins_cd(char **args, char **env);
int builtins_env(char **args, char **env);
int builtins_setenv(char **args, char **env);
int builtins_unsetenv(char **args, char **env);
int builtins_help(char **args, char **env);

#endif
