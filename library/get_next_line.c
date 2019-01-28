/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** try not to segfault, good luck :)
*/

#include <stddef.h> /* for NULL */
#include <unistd.h> /* for read */
#include <stdlib.h> /* for malloc, free */
#include "library.h"

int count_str_buf(char *buf, char *str)
{
    int c_buf = 0;
    int c_str = 0;

    for (; buf[c_buf] && buf[c_buf] != '\n'; c_buf++);
    for (; str && str[c_str] && str[c_str] != '\n'; c_str++);
    return c_buf + c_str;
}

char *malloc_read(int fd, int *size, char *buf, char *str)
{
    char *tmp = malloc(sizeof(char) * (count_str_buf(buf, str) + 1));
    int buf_eol = 0;
    int pos_str = 0;
    int pos_buf = 0;

    if (!tmp)
        return NULL;
    for (; str && str[pos_str]; pos_str++)
        tmp[pos_str] = str[pos_str];
    for (; buf && buf[pos_buf] && buf[pos_buf] != '\n'; pos_buf++)
        tmp[pos_buf + pos_str] = buf[pos_buf];
    buf_eol = (buf[pos_buf] == '\n') ? 1: 0;
    tmp[pos_buf + pos_str] = '\0';
    free(str);
    if (!buf_eol) {
        *size = read(fd, buf, READ_SIZE);
        (*size > 0) ? tmp = malloc_read(fd, size, buf, tmp) : 0;
    }
    return tmp;
}

char *get_next_line(int fd)
{
    char *str = NULL;
    int size = 1;
    static char buf[READ_SIZE + 1];
    int pos_eol = 0;
    int pos_end = 0;

    if (fd == -1 || !(str = malloc_read(fd, &size, buf, str)))
        return NULL;
    for (; buf[pos_eol] && buf[pos_eol] != '\n'; pos_eol++);
    pos_eol++;
    for (; buf[pos_eol]; pos_end++, pos_eol++)
        buf[pos_end] = buf[pos_eol];
    for (; buf[pos_end]; pos_end++)
        buf[pos_end] = '\0';
    if (size <= 0 && (!str || !str[0])) {
        free(str);
        return NULL;
    }
    return str;
}
