/*
** EPITECH PROJECT, 2018
** source/mysh
** File description:
** vim-epitech made by x4m3
*/

#include <stdio.h> /* for perror */
#include <stdlib.h> /* for free */
#include <unistd.h> /* for execve */
#include <sys/wait.h> /* for waitpid */
#include "mysh.h"
#include "config.h"
#include "colors.h"

void check_return(int *status)
{
    (WIFEXITED(*status)) ? 0 : putput("segmentation fault (core dumped)\n");
}

int fork_exec(char **command, int *status)
{
    pid_t parent = getpid();
    pid_t child = fork();

    if (parent != getpid()) {
        execve(command[0], command, NULL);
        exit(0);
    }
    waitpid(child, status, 0);
    return 0;
}

char *prompt_get_input(void)
{
    char *input_command;

    putput("%s%s%s ", c_bold_green, prompt, c_reset);
    input_command = get_next_line(0);
    return input_command;
}

int mysh(void)
{
    char *input_command;
    char **command;
    int status;

    while (1) {
        input_command = prompt_get_input();
        if (input_command == NULL) {
            putput("exit\n");
            return 0;
        }
        command = str_to_word_array(input_command, ' ');
        if (fork_exec(command, &status) != 0) {
            perror("error! aborting.\n");
            return 1;
        }
        check_return(&status);
        free_char_arr(command);
        free(input_command);
    }
    return 0;
}

int main(int ac, char **av, char **env)
{
    if (ac != 1 || mysh() == 1)
        return 84;
    return 0;
}
