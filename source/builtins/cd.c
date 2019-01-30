/*
** EPITECH PROJECT, 2018
** source/builtins/cd
** File description:
** if you code on paper, you're not a real programmer
*/

#include <unistd.h> /* for chdir */
#include "library.h"
#include "builtins.h"

int builtins_cd(char **args, char **env)
{
    if (args[0] == NULL)
        // chdir(into $HOME);
    putput("cd\n");
    return 0;
}
