/*
** EPITECH PROJECT, 2018
** dup_char_arr
** File description:
** duplicates a array of char
*/

#include <stdlib.h> /* for malloc */

int count_lines_arr(char **arr)
{
    int i = 0;

    for (; arr[i]; i++);
    return i - 1;
}

/* if nb_lines is unknown, for example if not using ac, set nb_lines to 0 */

char **dup_char_arr(char **src, int nb_lines)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **dup;

    if (!nb_lines)
        nb_lines = count_lines_arr(src);
    if (!(dup = malloc(sizeof(char *) * (nb_lines + 1))))
        return NULL;
    for (; src[i]; i++) {
        for (j = 0; src[i][j]; j++);
        if (!(dup[i] = malloc(sizeof(char) * (j + 1))))
            return NULL;
        for (k = 0; k < j; k++)
            dup[i][k] = src[i][k];
        dup[i][k] = '\0';
    }
    dup[i] = NULL;
    return dup;
}
