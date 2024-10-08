/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertion_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:24:53 by osredond          #+#    #+#             */
/*   Updated: 2024/07/09 22:25:02 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	printf_convertion_u(va_list args, int count)
{
	char			*str;
	unsigned int	c;
	int				w_check;

	c = va_arg(args, unsigned int);
	str = ft_utoa(c);
	if (str)
	{
		count = count + ft_strlen(str);
		w_check = ft_putstr_printf(str);
		free(str);
		if (w_check < 0)
			return (-1);
	}
	else
		return (-1);
	return (count);
}
