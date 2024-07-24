/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:55:46 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 21:56:02 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "../libft.h"

size_t	ft_strlen(const char	*str)
{
	size_t	len;

	len = 0;
	while (*str != 0)
	{
		str++;
		len++;
	}
	return (len);
}
/*
int	main(void)
{
	char	*texto;
	int		len;

	texto = "Hola";
	len = ft_strlen(texto);
	printf("El texto es :%s\n y la longitud es de %d caracteres\n", texto, len);
	return (0);
}*/
