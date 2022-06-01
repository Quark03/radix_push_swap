/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f@student.42lisboa.com <acinca-f>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:19:06 by acinca-f@student  #+#    #+#             */
/*   Updated: 2021/10/20 09:34:25 by acinca-f@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;
	size_t	memory;

	memory = count * size;
	dest = malloc(memory);
	if (!dest)
		return (0);
	return (dest);
}

// int	main(void)
// {
// 	char	*str;

// 	str = calloc(4, sizeof(char));
// 	str = "ABCD";
// 	printf("String <%s>\n", str);
// }
