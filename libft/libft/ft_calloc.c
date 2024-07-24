/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:41:07 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 20:41:19 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
//#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_bytes;
	void	*result;

	total_bytes = count * size;
	result = malloc(total_bytes);
	if (result)
		ft_bzero(result, total_bytes);
	return (result);
}
/*
int	main(void)
{
	int	*numbers;
	int	index;

	numbers = ft_calloc (100, sizeof (int));
	index = 0;
	while (index < 100)
	{
		printf("%d", numbers[index]);
		index++;
	}
	return (0);
}*/
