/*
** EPITECH PROJECT, 2018
** source/mysh
** File description:
** vim-epitech made by x4m3
*/

#include <stdio.h> /* for perror */
#include <stdlib.h> /* for free */
#include <unistd.h> /* for isatty */
#include "mysh.h"

int loop(t_colors *colors, char **env)
{
    char *input_command;
    char **command;
    static int status = 0;

    input_command = prompt_get_input(colors, &status);
    if (!input_command) {
        (isatty(0) == 1) ? putput("\n") : 0;
        return -1;
    }
    command = str_to_word_array(input_command, ' ');
    if (*command[0] == '\0') {
        free_char_arr(command);
        return 0;
    }
    exec(command, &status, env);
    check_return(&status, colors, command[0]);
    free_char_arr(command);
    return 0;
}

int mysh(char **env, t_colors *colors)
{
    char **my_env = dup_char_arr(env, 0);

    while (1) {
        if (loop(colors, my_env) == -1) {
            free_char_arr(my_env);
            return 0;
        }
    }
    free_char_arr(my_env);
    return 0;
}

int main(int ac, char **av, char **env)
{
    t_colors *colors = init_t_colors();

    if (!colors)
        return 84;
    if (ac != 1) {
        putput_err("%s: no arguments needed\n", av[0]);
        return 84;
    }
    mysh(env, colors);
    return 0;
}
