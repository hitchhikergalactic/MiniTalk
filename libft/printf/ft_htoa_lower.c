/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa_lower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:26:54 by osredond          #+#    #+#             */
/*   Updated: 2024/07/09 22:27:05 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_htoa_lower(unsigned long n)
{
	char	*result;
	int		index;

	result = ft_htoa (n);
	if (!result)
		return (NULL);
	index = 0;
	while (result [index] != '\0')
	{
		result[index] = ft_tolower(result [index]);
		index++;
	}
	return (result);
}
/*
int	main(void)
{
	char	*result;

	result = ft_htoa_lower(255);
	printf("%s\n", result);
	free (result);
	result = ft_htoa_lower(0);
	printf("%s\n", result);
	free (result);
	result = ft_htoa_lower(15);
	printf("%s\n", result);
	free (result);
	result = ft_htoa_lower(2568945);
	printf("%s\n", result);
	free (result);
}*/
