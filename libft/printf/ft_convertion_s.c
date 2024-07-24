/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertion_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:02:29 by osredond          #+#    #+#             */
/*   Updated: 2024/07/09 22:02:38 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	printf_convertion_s(va_list args, int count)
{
	char	*str;
	int		w_check;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		w_check = ft_putstr_printf("(null)");
		if (w_check < 0)
			return (-1);
		count = count + 6;
	}
	else
	{
		w_check = ft_putstr_printf(str);
		if (w_check < 0)
			return (-1);
		count = count + ft_strlen(str);
	}
	return (count);
}
