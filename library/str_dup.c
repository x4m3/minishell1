/*
** EPITECH PROJECT, 2018
** str_dup
** File description:
** duplicate a string (malloc and copy from another string)
*/

#include <stdlib.h> /* for malloc */
#include "library.h" /* for str_copy */

char *str_dup(const char *src)
{
    char *str;

    if (!src || !(str = malloc(sizeof(char) * len_str(src))))
        return NULL;
    return str_copy(str, src);
}
