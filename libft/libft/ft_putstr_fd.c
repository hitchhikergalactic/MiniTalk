/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:43:34 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 21:43:50 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putstr_fd(char	*s, int fd)
{
	int	index;

	index = 0;
	while (s[index] != 0)
	{
		ft_putchar_fd (s[index], fd);
		index++;
	}
}
/*
int	main(void)
{
	int	stdout_fd;

	stdout_fd = 1;
	ft_putstr_fd("Susana Nunez Zamora", stdout_fd);
	write (1, "\n", 1);
	return (0);
}*/
