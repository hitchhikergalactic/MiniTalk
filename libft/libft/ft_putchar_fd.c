/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:41:07 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 21:41:15 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
/*
int	main(void)
{
	int	stdout_fd;

	stdout_fd = 1;
	ft_putchar_fd ('S', stdout_fd);
	ft_putchar_fd ('U', stdout_fd);
	ft_putchar_fd ('S', stdout_fd);
	ft_putchar_fd ('A', stdout_fd);
	ft_putchar_fd ('N', stdout_fd);
	ft_putchar_fd ('A', stdout_fd);
	ft_putchar_fd ('\n', stdout_fd);
	return (0);
}*/
