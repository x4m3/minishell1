/*
** EPITECH PROJECT, 2018
** source/mysh
** File description:
** vim-epitech made by x4m3
*/

#include <stdio.h> /* for perror */
#include <stdlib.h> /* for free */
#include "mysh.h"

int loop(t_colors *colors, char **env)
{
    char *input_command;
    char **command;
    int status;

    input_command = prompt_get_input(colors);
    if (input_command == NULL || !str_compare(input_command, "exit")) {
        putput("exit\n");
        free(input_command);
        return -1;
    }
    command = str_to_word_array(input_command, ' ');
    if (fork_exec(command, &status, env) != 0) {
        perror("error! aborting.\n");
        free_char_arr(command);
        free(input_command);
        return 1;
    }
    check_return(&status, colors);
    free_char_arr(command);
    free(input_command);
    return 0;
}

int mysh(char **env, t_colors *colors)
{
    while (1) {
        if (loop(colors, env) == -1)
            return 0;
    }
    return 0;
}

int main(int ac, char **av, char **env)
{
    t_colors *colors = init_t_colors();
    int ret = 0;

    (void)av;
    ret = (ac != 1 || !colors || mysh(env, colors) != 0) ? 84 : 0;
    free(colors);
    if (ret == 84)
        return 84;
    return 0;
}
