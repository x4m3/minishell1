/*
** EPITECH PROJECT, 2018
** putput_err
** File description:
** put_str_err on steroids
*/

#include <stdarg.h> /* for varargs */
#include <unistd.h> /* for write */
#include "library.h" /* for len_str */

void put_char_err(char c)
{
    write(2, &c, 1);
}

void put_str_err(const char *str)
{
    write(2, str, len_str(str) - 1);
}

void put_nbr_err(int nb)
{
    if (nb == -2147483648) {
        put_str_err("-2147483648");
        return;
    }
    if (nb < 0) {
        nb *= -1;
        put_char_err('-');
    }
    if (nb / 10 != 0)
        put_nbr_err(nb / 10);
    put_char_err((nb % 10) + '0');
}

int putput_err(char *str, ...)
{
    va_list list;

    va_start(list, str);
    for (int i = 0; str[i]; i++) {
        (str[i] != '%') ? put_char_err(str[i]) : 0;
        if (str[i] == '%') {
            (str[i + 1] == 'i') ? put_nbr_err(va_arg(list, int)) : 0;
            (str[i + 1] == 'c') ? put_char_err(va_arg(list, int)) : 0;
            (str[i + 1] == 's') ? put_str_err(va_arg(list, char *)) : 0;
            (str[i + 1] == '%') ? put_char_err('%') : 0;
            i++;
        }
    }
    va_end(list);
    return 0;
}
