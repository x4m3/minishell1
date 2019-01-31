/*
** EPITECH PROJECT, 2018
** str_n_compare
** File description:
** compare n characters of 2 strings
*/

int str_n_compare(const char *s1, const char *s2, const int n)
{
    if (!s1 && !s2 && !n)
        return 1;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i])
            return 1;
    }
    return 0;
}
