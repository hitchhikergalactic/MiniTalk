/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:29:02 by osredond          #+#    #+#             */
/*   Updated: 2024/07/09 22:29:12 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putstr_printf(const char	*str)
{
	return (write (1, str, ft_strlen(str)));
}
/*
int	main(void)
{
	char	*str;
	
    str = "Susana";
	ft_putstr_printf(str);
	write (1, "\n", 1);
	return (0);
}*/
