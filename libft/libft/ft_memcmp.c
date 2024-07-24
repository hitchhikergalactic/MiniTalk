/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:36:43 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 21:37:06 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stddef.h>

int	ft_memcmp(const void	*s1, const void	*s2, size_t n)
{
	size_t			index;
	unsigned char	*aux1;
	unsigned char	*aux2;
	int				result_cmp;

	aux1 = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		result_cmp = *aux1 - *aux2;
		if (result_cmp != 0)
		{
			return (result_cmp);
		}
		else
		{
			aux1++;
			aux2++;
			index++;
		}
	}
	return (0);
}
/*
int	main(void)
{
	int	result;

	result = ft_memcmp ("t\200", "t\0", 2);
	printf("%d\n", result);
	result = ft_memcmp ("t\200", "t\0", 2);
	printf("%d\n", result);
	result = ft_memcmp ("Hola", "Hola", 3);
	printf("%d\n", result);
	result = ft_memcmp ("Hola", "Hala", 3);
	printf("%d\n", result);
	result = ft_memcmp ("cola", "coma", 3);
	printf("%d\n", result);
	result = ft_memcmp ("Hola", "Hola susana", 3);
	printf("%d\n", result);
	result = ft_memcmp ("Hola", "Hola susana", 6);
	printf("%d\n", result);
	result = ft_memcmp ("Hola", "Hola Su", 4);
	printf("%d\n", result);
	return (0);
}*/
