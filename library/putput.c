/*
** EPITECH PROJECT, 2018
** putput
** File description:
** put_str on steroids
*/

#include <stdarg.h> /* for varargs */
#include <unistd.h> /* for write */
#include "library.h" /* for len_str */

void put_char(char c)
{
    write(1, &c, 1);
}

void put_str(const char *str)
{
    write(1, str, len_str(str) - 1);
}

void put_nbr(int nb)
{
    if (nb == -2147483648) {
        put_str("-2147483648");
        return;
    }
    if (nb < 0) {
        nb *= -1;
        put_char('-');
    }
    if (nb / 10 != 0)
        put_nbr(nb / 10);
    put_char((nb % 10) + '0');
}

int putput(char *str, ...)
{
    va_list list;

    va_start(list, str);
    for (int i = 0; str[i]; i++) {
        (str[i] != '%') ? put_char(str[i]) : 0;
        if (str[i] == '%') {
            (str[i + 1] == 'i') ? put_nbr(va_arg(list, int)) : 0;
            (str[i + 1] == 'c') ? put_char(va_arg(list, int)) : 0;
            (str[i + 1] == 's') ? put_str(va_arg(list, char *)) : 0;
            (str[i + 1] == '%') ? put_char('%') : 0;
            i++;
        }
    }
    va_end(list);
    return 0;
}
