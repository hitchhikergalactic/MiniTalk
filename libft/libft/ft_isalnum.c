/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:43:52 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 20:44:03 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*#include <stdio.h>*/

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*
int	main(void)
{
	int	c;

	c = ft_isalnum ('9');
	printf("%d\n", c);
	c = ft_isalnum ('G');
	printf("%d\n", c);
	c = ft_isalnum ('!');
	printf("%d\n", c);
	c = ft_isalnum ('?');
	printf("%d\n", c);
	return (0);
}*/
