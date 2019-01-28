/*
** EPITECH PROJECT, 2018
** gnl_stdin
** File description:
** getline on stdin
*/

#include <stdio.h> /* for getline */
#include <stdlib.h> /* for free */
#include "library.h" /* for len_str */

int len_str_n(const char *str)
{
    int i = 0;

    for (; str[i] != '\n'; i++);
    return i;
}

char *gnl_stdin(void)
{
    char *buf = NULL;
    char *str;
    size_t len = 0;
    int i = 0;

    if (getline(&buf, &len, stdin) == -1) {
        free(buf);
        return NULL;
    }
    str = malloc(sizeof(char) * (len_str_n(buf) + 1));
    for (; buf[i] != '\n'; i++)
        str[i] = buf[i];
    str[i] = '\0';
    free(buf);
    return str;
}
