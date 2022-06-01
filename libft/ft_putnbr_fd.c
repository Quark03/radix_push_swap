/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:18:03 by acinca-f@st       #+#    #+#             */
/*   Updated: 2022/06/01 21:16:18 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			ft_putnbr_fd(-21, fd);
			ft_putnbr_fd(47483648, fd);
			return ;
		}
		ft_putchar_fd('-', fd);
		nb = nb * -1;
	}
	if (nb >= 0 && nb < 10)
	{
		nb = nb + '0';
		ft_putchar_fd(nb, fd);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		nb = nb % 10 + '0';
		ft_putchar_fd(nb, fd);
	}
}
