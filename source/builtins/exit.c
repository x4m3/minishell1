/*
** EPITECH PROJECT, 2018
** source/builtins/exit
** File description:
** 01100010 01101001 01101110 01100001 01110010 01111001
*/

#include <stdlib.h> /* for exit */
#include "library.h"
#include "builtins.h"

int builtins_exit(char **args, char **env)
{
    (void)env;
    (args[0] == NULL) ? putput("\n") : 0;
    free_char_arr(args);
    free_char_arr(env);
    exit(0);
}
