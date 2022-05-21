//
// Created by quark on 21-05-2022.
//

#include "../push_swap.h"

static int ft_isspace(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return (1);
    else if (c == '\v' || c == '\f' || c == '\r')
        return (1);
    return (0);
}

long long_atoi(const char *str)
{
    int		sign;
    long	r;

    r = 0;
    sign = 1;
    while (ft_isspace(*str))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (ft_isdigit(*str))
    {
        r = r * 10 + *str - '0';
        str++;
    }
    return (sign * r);
}