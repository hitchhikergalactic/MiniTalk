/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertion_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:02:01 by osredond          #+#    #+#             */
/*   Updated: 2024/07/09 22:02:11 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	printf_convertion_p(va_list args, int count)
{
	void	*p;
	char	*str;

	p = va_arg(args, void *);
	if (ft_putstr_printf("0x") < 0)
		return (-1);
	str = ft_htoa_lower((unsigned long)p);
	if (!str)
	{
		free (str);
		return (-1);
	}
	count = count + 2 + ft_strlen (str);
	if (ft_putstr_printf(str) < 0)
	{
		free (str);
		return (-1);
	}
	free (str);
	return (count);
}
