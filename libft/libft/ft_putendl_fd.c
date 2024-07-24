/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:41:43 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 21:41:55 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putendl_fd(char	*s, int fd)
{
	ft_putstr_fd (s, fd);
	ft_putchar_fd ('\n', fd);
}
/*
int	main(void)
{
	int	stdout_fd;

	stdout_fd = 1;
	ft_putendl_fd ("Susana Nunez Zamora", stdout_fd);
	ft_putendl_fd ("Archivo encriptado", stdout_fd);
	return (0);
}*/
