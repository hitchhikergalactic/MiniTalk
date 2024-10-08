/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:26:09 by osredond          #+#    #+#             */
/*   Updated: 2024/07/09 22:26:23 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "../libft.h"

static int	ft_cont_len(unsigned long n)
{
	unsigned int	size_n;

	if (n == 0)
		return (2);
	size_n = 0;
	while (n != 0)
	{
		n = n / 16;
		size_n++;
	}
	return (size_n + 1);
}

static char	ft_hexadigit(int digit)
{
	char	*convertion_table;

	convertion_table = "0123456789ABCDEF";
	return (convertion_table[digit]);
}

static char	ft_lastdigit(unsigned long n)
{
	int		last_digit;
	char	result;

	last_digit = (n % 16);
	result = ft_hexadigit(last_digit);
	return (result);
}

char	*ft_htoa(unsigned long n)
{
	int		last_index;
	char	*buffer;

	buffer = (char *) ft_calloc (ft_cont_len(n), sizeof(char));
	if (buffer == NULL)
		return (NULL);
	if (n == 0)
	{
		ft_strlcpy(buffer, "0", 4);
		return (buffer);
	}
	last_index = ft_cont_len(n) -2;
	while (n != 0)
	{
		buffer [last_index] = ft_lastdigit(n);
		n = n / 16;
		last_index--;
	}
	return (buffer);
}
/*
int	main(void)
{
	char	*result;

	result = ft_htoa (123);
	printf("%s\n", result);
	free(result);
	result = ft_htoa (-123);
	printf("%s\n", result);
	free(result);
	result = ft_htoa (0);
	printf("%s\n", result);
	free(result);
	result = ft_htoa (1111111111125638);
	printf("%s\n", result);
	free(result);
	result = ft_htoa (5356);
	printf("%s\n", result);
	free(result);
	result = ft_htoa (15);
	printf("%s\n", result);
	free(result);
}*/
