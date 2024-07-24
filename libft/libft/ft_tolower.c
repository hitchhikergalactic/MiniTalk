/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:07:01 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 22:07:12 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c - ('A' - 'a');
	return (c);
}
/*
int	main(void)
{
	char	c;
	char	lc;

	c = 'A';
	lc = ft_tolower(c);
	printf("%c\n", lc);
	c = 'F';
	lc = ft_tolower(c);
	printf("%c\n", lc);
	return (0);
}*/
