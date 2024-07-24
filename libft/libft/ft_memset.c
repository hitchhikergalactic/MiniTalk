/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:39:53 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 21:40:21 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

void	*ft_memset(void	*b, int c, size_t len)
{
	size_t	index;
	char	*temp;

	temp = (char *) b;
	index = 0;
	while (index < len)
	{
		*temp = c;
		temp++;
		index++;
	}
	return (b);
}
/*
int	main(void)
{
	char	str1[5] = "Hola";
	char	str2[5] = "1234";

	printf("%s\n", ft_memset(str1, 34, 3));
	printf("%s\n", ft_memset(str2, 97, 3));
}*/
