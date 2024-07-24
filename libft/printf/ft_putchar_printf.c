/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:28:09 by osredond          #+#    #+#             */
/*   Updated: 2024/07/09 22:28:20 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar_printf(char c)
{
	return (write (1, &c, 1));
}
/*
int	main(void)
{
	char	c;
	
    c = ft_putstr_printf('i');
	write (1, "\n", 1);
	return (0);
}*/
