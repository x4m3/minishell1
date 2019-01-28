/*
** EPITECH PROJECT, 2018
** source/prompt
** File description:
** csfml is the best thing ever
*/

#include "mysh.h"

void prompt(t_colors *colors)
{
    putput("%s", colors->current);
    putput("%s", "$");
    putput("%s", colors->reset);
    putput(" ");
}

char *prompt_get_input(t_colors *colors)
{
    char *input_command;

    prompt(colors);
    input_command = get_next_line(0);
    return input_command;
}
