/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:47:22 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 20:47:33 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	int	c;

	c = ft_isprint(60);
	printf("%d\n", c);
	c = ft_isprint('A');
	printf("%d\n", c);
	c = ft_isprint(250);
	printf("%d\n", c);
	c = ft_isprint(158);
	printf("%d\n", c);
	return (0);
}*/
