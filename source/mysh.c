/*
** EPITECH PROJECT, 2018
** source/mysh
** File description:
** vim-epitech made by x4m3
*/

#include <unistd.h> /* for execve */
#include "mysh.h"
#include "config.h"
#include "colors.h"

void mysh(void)
{
    putput("%s%s%s ", c_bold_green, prompt, c_reset);
}

int main(void)
{
    mysh();
    return EXIT_OKAY;
}
