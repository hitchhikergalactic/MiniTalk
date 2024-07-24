/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertion_X.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:59:49 by osredond          #+#    #+#             */
/*   Updated: 2024/07/09 22:00:01 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	printf_convertion_x(va_list args, int count)
{
	char					*str;
	unsigned long			ld;
	int						w_check;

	ld = va_arg(args, unsigned int);
	str = ft_htoa(ld);
	if (str)
	{
		count = count + ft_strlen(str);
		w_check = ft_putstr_printf(str);
		free(str);
		if (w_check < 0)
			return (-1);
	}
	return (count);
}
