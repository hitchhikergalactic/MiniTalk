/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_porcentaje.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:58:26 by osredond          #+#    #+#             */
/*   Updated: 2024/07/09 21:58:37 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	printf_conv_porcentaje(int count)
{
	int	w_check;

	w_check = ft_putchar_printf('%');
	if (w_check < 0)
		return (-1);
	count++;
	return (count);
}
