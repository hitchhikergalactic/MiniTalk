/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:42:24 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 21:42:44 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <unistd.h>

static void	ft_putnbr_without_sign(unsigned int n, int fd)
{
	char	digit;

	if (n == 0)
	{
		return ;
	}
	ft_putnbr_without_sign(n / 10, fd);
	digit = (n % 10) + '0';
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	unsigned_n;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		unsigned_n = (n * -1);
	}
	else
		unsigned_n = n;
	ft_putnbr_without_sign(unsigned_n, fd);
}
/*
int	main(void)
{
	int	stdout_fd;

	stdout_fd = 1;
	ft_putnbr_fd(0, stdout_fd);
	printf("\n");
	ft_putnbr_fd(555, stdout_fd);
	printf("\n");
	ft_putnbr_fd(-555, stdout_fd	;
	printf("\n");
	ft_putnbr_fd(-1247000, stdout_fd);
	printf("\n");
	ft_putnbr_fd(0, stdout_fd);
	printf("\n");
 	ft_putnbr_fd(35, stdout_fd);
	printf("\n");
 	ft_putnbr_fd(2147483647, stdout_fd);
	printf("\n");
 	ft_putnbr_fd(-2147483648, stdout_fd);
	printf("\n");
	return (0);
}*/
