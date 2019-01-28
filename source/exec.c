/*
** EPITECH PROJECT, 2018
** source/exec
** File description:
** segmentation fault (core dumped)
*/

#include <unistd.h> /* for execve */
#include <sys/wait.h> /* for waitpid */
#include <stdlib.h> /* for exit */
#include "mysh.h"

void check_return(int *status, t_colors *colors)
{
    if (WIFEXITED(*status)) {
        putput("segmentation fault (core dumped)\n");
        colors->current = colors->bold_red;
    }
    else
        colors->current = colors->bold_green;
}

int fork_exec(char **command, int *status, char **env)
{
    pid_t parent = getpid();
    pid_t child = fork();

    if (parent != getpid()) {
        if (execve(command[0], command, env) == -1) {
            putput("command not found\n");
            exit(0);
        }
    }
    waitpid(child, status, 0);
    return 0;
}
