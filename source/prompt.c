/*
** EPITECH PROJECT, 2018
** source/prompt
** File description:
** csfml is the best thing ever
*/

#include "mysh.h"

void disp_prompt(t_colors *colors, int status)
{
    putput("%i ", status);
    putput("%s", colors->current);
    putput("%s", "$");
    putput("%s", colors->reset);
    putput(" ");
}

char *prompt_get_input(t_colors *colors, int *status)
{
    char *input_command;

    disp_prompt(colors, *status);
    input_command = gnl_stdin();
    return input_command;
}
