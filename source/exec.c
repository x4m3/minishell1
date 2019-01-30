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
#include "builtins.h"

void check_return(int *status, t_colors *colors)
{
    (*status == 139) ? putput("segmentation fault (core dumped)\n") : 0;
    colors->current = (!(*status)) ? colors->bold_green : colors->bold_red;
}

int fork_exec(char **command, int *status, char **env)
{
    pid_t parent = getpid();
    pid_t child = fork();
    int wait_pid = 0;

    *status = 0;
    if (parent != getpid()) {
        execve(command[0], command, env);
        exit(0);
    }
    else {
        while (*status == 0 && wait_pid != -1)
            wait_pid = waitpid(child, status, WUNTRACED | WCONTINUED);
    }
    return 0;
}

int exec(char **command, int *status, char **env)
{
    if (command[0] == NULL)
        builtins_exit(command);
    for (int i = 0; i < list_builtins(); i++) {
        if (!str_compare(command[0], builtins_str[i]))
            return (*builtins_function[i])(command);
    }
    return fork_exec(command, status, env);
}
