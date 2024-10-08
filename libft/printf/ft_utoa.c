/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:30:08 by osredond          #+#    #+#             */
/*   Updated: 2024/07/09 22:30:23 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_cont_len(unsigned int n)
{
	unsigned int	size_n;

	if (n == 0)
		return (2);
	size_n = 0;
	while (n != 0)
	{
		n = n / 10;
		size_n++;
	}
	return (size_n + 1);
}

static char	ft_lastdigit(unsigned int n)
{
	char	last_digit;

	last_digit = (n % 10) + '0';
	return (last_digit);
}

char	*ft_utoa(unsigned int n)
{
	int		last_index;
	char	*buffer;

	buffer = (char *)ft_calloc (ft_cont_len (n), sizeof(char));
	if (buffer == NULL)
		return (NULL);
	if (n == 0)
	{
		ft_strlcpy(buffer, "0", 2);
		return (buffer);
	}
	last_index = ft_cont_len (n) - 2;
	while (n != 0)
	{
		buffer[last_index] = ft_lastdigit(n);
		n = n / 10;
		last_index--;
	}
	return (buffer);
}
/*
int main(void)
{
	char	*result;

    printf ("%d\n", ft_cont_len(-1));
	result = ft_utoa(1);
	printf("%s\n", result);
	free (result);
    result = ft_utoa(1231);
	printf("%s\n", result);
	free (result);
    result = ft_utoa(-123);
	printf("%s\n", result);
	free (result);
    result = ft_utoa(567890345678561);
	printf("%s\n", result);
	free (result);
    result = ft_utoa(1);
	printf("%s\n", result);
	free (result);
    result = ft_utoa(1);
	printf("%s\n", result);
	free(result);
} */
