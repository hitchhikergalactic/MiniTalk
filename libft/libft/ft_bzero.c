/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:40:18 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 20:40:36 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
int	main(void)
{
	char	src[5] = "Hola";
	char	src2[10] = "123456789";

	ft_bzero(src, 3);
	printf("%s\n", src);
	ft_bzero(src2, 3);
	printf("%s\n", src2);
}*/
