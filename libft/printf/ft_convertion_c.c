/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertion_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:00:23 by osredond          #+#    #+#             */
/*   Updated: 2024/07/09 22:00:33 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	printf_convertion_c(va_list args, int count)
{
	int		c;
	int		w_check;

	c = va_arg(args, int);
	w_check = ft_putchar_printf(c);
	if (w_check < 0)
		return (-1);
	count++;
	return (count);
}
