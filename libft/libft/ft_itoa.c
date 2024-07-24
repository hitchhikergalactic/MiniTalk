/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:48:00 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 20:48:54 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "../libft.h"

static int	ft_cont_len(int n)

{
	int	size_n;

	if (n == 0)
		return (2);
	if (n > 0)
		size_n = 0;
	if (n < 0)
		size_n = 1;
	while (n != 0)
	{
		n = n / 10;
		size_n++;
	}
	return (size_n + 1);
}

static char	ft_lastdigit(int n)
{
	char	last_digit;

	if (n > 0)
		last_digit = (n % 10) + '0';
	if (n < 0)
		last_digit = '0' -(n % 10);
	return (last_digit);
}

char	*ft_itoa(int n)
{
	int		last_index;
	char	*len;

	len = (char *)ft_calloc (ft_cont_len (n), sizeof(char));
	if (len == 0)
		return (0);
	if (n == 0)
	{
		ft_strlcpy(len, "0", 2);
		return (len);
	}
	if (n < 0)
		len[0] = '-';
	last_index = ft_cont_len (n) - 2;
	while (n != 0)
	{
		len [last_index] = ft_lastdigit(n);
		n = n / 10;
		last_index--;
	}
	return (len);
}
/*
int	main(void)
{
	char	*len;

	len = ft_itoa (-2147483648);
	printf ("%s\n", len);
	len = ft_itoa (0);
	printf ("%s\n", len);
	len = ft_itoa (2147483647); 
	printf ("%s\n", len);
	len = ft_itoa (2); 
	printf ("%s\n", len);
	len = ft_itoa (-2); 
	printf ("%s\n", len);
	len = ft_itoa (21448);
	printf ("%s\n", len);
	return (0);
}*/
