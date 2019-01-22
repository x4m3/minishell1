/*
** EPITECH PROJECT, 2018
** free_char_arr
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h> /* for free */

void free_char_arr(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
