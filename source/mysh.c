/*
** EPITECH PROJECT, 2018
** source/mysh
** File description:
** vim-epitech made by x4m3
*/

#include <stdlib.h> /* for free */
#include <unistd.h> /* for execve */
#include "mysh.h"
#include "config.h"
#include "colors.h"

void mysh(void)
{
    char *input_command;
    char **command;

    while (1) {
    putput("%s%s%s ", c_bold_green, prompt, c_reset);
    input_command = get_next_line(0);
    putput("\n");
    if (input_command == NULL)
        break;
    command = str_to_word_array(input_command, ' ');
    // execve
    free_char_arr(command);
    }
    free(input_command);
}

int main(void)
{
    mysh();
    return EXIT_OKAY;
}
