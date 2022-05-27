//
// Created by quark on 18-05-2022.
//
#include "libft.h"

size_t	ft_strlen(const char *s)
{
    size_t	c;

    c = 0;
    while (s[c] != '\0')
        c++;
    return (c);
}