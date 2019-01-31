/*
** EPITECH PROJECT, 2018
** str_copy
** File description:
** copies a string into another
*/

char *str_copy(char *dest, const char *src)
{
    int i = 0;

    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
