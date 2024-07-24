/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:37:56 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 21:38:16 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

void	*ft_memcpy(void	*dst, const void	*src, size_t n)
{
	size_t		index;
	char		*dest1;
	const char	*src1;

	dest1 = (char *) dst;
	src1 = (const char *) src;
	index = 0;
	if (dest1 == 0 && src1 == 0)
		return (0);
	while (index < n)
	{
		dest1 [index] = src1 [index];
		index++;
	}
	return (dst);
}
/*
int	main(void)
{
	char	src [] = "0";
	char	dest [5] = "0";

	printf("%s\n", ft_memcpy(dest, src, 5));
	printf("%s\n", dest);
	return (0);
}*/
