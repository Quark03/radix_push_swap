//
// Created by quark on 18-05-2022.
//
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}