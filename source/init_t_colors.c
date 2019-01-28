/*
** EPITECH PROJECT, 2018
** source/init_t_colors
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h> /* for malloc */
#include <stddef.h> /* for NULL */
#include "colors.h"

t_colors *init_t_colors(void)
{
    t_colors *colors = malloc(sizeof(t_colors));

    if (!colors)
        return NULL;
    colors->reset = "\033[0m";
    colors->bold_red = "\033[1;31m";
    colors->bold_green = "\033[1;32m";
    colors->current = colors->bold_green;
    return colors;
}
