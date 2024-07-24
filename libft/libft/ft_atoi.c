/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:39:26 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 20:39:32 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
//#include <stdio.h>

static int	ft_isspace(const char *str)
{
	if (*str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\r' || *str == ' ' || *str == 11)
		return (1);
	else
		return (0);
}

static int	convert_to_int(const char	*str)
{
	char	digit;
	int		value;

	value = 0;
	while (ft_isdigit (*str))
	{
		digit = (*str - '0');
		value = (value * 10) + digit;
		str++;
	}
	return (value);
}

int	ft_atoi(const char	*str)
{
	int		value;
	char	is_negative;		

	while (ft_isspace(str))
	{
		str++;
	}
	is_negative = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_negative = 1;
		else
			is_negative = 0;
		str++;
	}
	value = convert_to_int (str);
	if (is_negative)
		value = (value * -1);
	return (value);
}
/*
int	main(void)
{
	int	value;

	value = atoi("--+-300");
	printf("%d\n", value);
	value = ft_atoi("--+-300");
	printf("%d\n", value);

	value = atoi("   300");
	printf("%d\n", value);
	value = ft_atoi("   300");
	printf("%d\n", value);
	
	value = atoi("+300");
	printf("%d\n", value);
	value = ft_atoi("+300");
	printf("%d\n", value);

	value = atoi("-2147483648");
	printf("%d\n", value);
	value = ft_atoi("-2147483648");
	printf("%d\n", value);
	
	value = atoi(" ");
	printf("%d\n", value);
	value = ft_atoi(" ");
	printf("%d\n", value);
}*/
