/*
** EPITECH PROJECT, 2018
** include/library
** File description:
** vim-epitech made by x4m3
*/

#ifndef LIBRARY_H
#define LIBRARY_H

#include "get_next_line.h"

int len_str(const char *str);
int putput(char *str, ...);
int putput_err(char *str, ...);
char **str_to_word_array(const char *str, const char sep);
void free_char_arr(char **array);

#endif
