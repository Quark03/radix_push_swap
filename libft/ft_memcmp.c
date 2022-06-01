/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:07:14 by acinca-f@st       #+#    #+#             */
/*   Updated: 2022/06/01 21:16:02 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = s1;
	str2 = s2;
	while (n--)
	{
		if (*str1++ != *str2++)
			return (*--str1 - *--str2);
	}
	return (0);
}

// int	main(void)
// {
// 	printf("Res <%d> \n", ft_memcmp("Hello world", "Hello Peter", 11));
// 	printf("Or  <%d> \n", memcmp("Hello world", "Hello Peter", 11));
// }
