/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertion_d_i.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:00:57 by osredond          #+#    #+#             */
/*   Updated: 2024/07/09 22:01:06 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	printf_convertion_d_i(va_list args, int count)
{
	int		c;
	char	*str;
	int		w_check;

	c = va_arg(args, int);
	str = ft_itoa (c);
	if (str)
	{
		count = count + ft_strlen(str);
		w_check = ft_putstr_printf(str);
		free (str);
		if (w_check < 0)
			return (-1);
	}
	else
		return (-1);
	return (count);
}
