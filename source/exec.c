/*
** EPITECH PROJECT, 2018
** source/exec
** File description:
** segmentation fault (core dumped)
*/

#include <unistd.h> /* for execve, access */
#include <sys/wait.h> /* for waitpid */
#include <stdlib.h> /* for exit */
#include <string.h> /* for strsignal */
#include <signal.h> /* for WTERMSIG */
#include <errno.h> /* for errno */
#include "mysh.h"
#include "builtins.h"

void check_return(int *status, t_colors *colors, char *command)
{
    colors->current = (!(*status)) ? colors->bold_green : colors->bold_red;
    if (*status == -1) {
        putput_err("Command not found.\n");
        *status = 1;
        return;
    }
    if (!WIFSIGNALED(*status))
        return;
    if (WTERMSIG(*status) == 8) {
        putput("Floating exception\n");
        return;
    }
    if (WTERMSIG(*status) == 11) {
        putput("Segmentation fault\n");
        return;
    }
    putput("%s: %s.\n", command, strsignal(WTERMSIG(*status)));
}

int check_command(char **command, int *status)
{
    if (access(command[0], F_OK | X_OK) == -1) {
        *status = -1;
        return 1;
    }
    return 0;
}

int fork_exec(char **command, int *status, char **env)
{
    pid_t parent = getpid();
    pid_t child;
    int wait_pid = 0;

    *status = 0;
    child = fork();
    if (parent != getpid()) {
        execve(command[0], command, env);
        if (errno == ENOEXEC)
            putput("%s: Exec format error. Wrong Architecture.\n", command[0]);
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
    char **path;
    char *dup_command = command[0];

    if (command[0] == NULL)
        builtins_exit(command, env);
    for (int i = 0; i < list_builtins(); i++) {
        if (!str_compare(command[0], builtins_str[i]))
            return (*builtins_function[i])(command, env);
    }
    if (check_command(command, status) == 0)
        return fork_exec(command, status, env);
    path = move_path_pointer(str_to_word_array(get_path(env), ':'));
    for (int i = 0; path[i]; i++) {
        command[0] = full_path_command(path[i], dup_command);
        if (check_command(command, status) == 0)
            return fork_exec(command, status, env);
    }
    command[0] = dup_command;
    if (check_command(command, status) == 0)
        return fork_exec(command, status, env);
    putput_err("%s: ", command[0]);
    *status = -1;
    return 0;
}
