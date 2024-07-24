/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:46:05 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 20:46:18 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	int c;

	c = ft_isascii ('b');
	printf("%d\n", c);
	c = ft_isascii ('5');
	printf("%d\n", c);
	c = ft_isascii (250);
	printf("%d\n", c);
	c = ft_isascii ('9850');
	printf("%d\n", c);
	return (0);
}*/
