/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:00:26 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 22:00:45 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "../libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	char	*last_ocurrence;

	if (c > 255)
		c = (c % 256);
	last_ocurrence = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			last_ocurrence = (char *)s;
		}
		s++;
	}
	if (last_ocurrence != 0)
		return (last_ocurrence);
	else if (c == '\0')
		return ((char *)s);
	else
		return (0);
}
/*
int	main(void)

{
	char	*result;

	result = ft_strrchr("Hola", 'o');
	printf("%s\n", result);
	result = ft_strrchr("Hola", 'e');
	if (result == 0)
		printf("No se ha encontrado\n");
	result = ft_strrchr("Hola", 'o' + 256 );
	printf("%s\n", result);
	result = ft_strrchr("Hola", '\0');
	if (result == 0)
		printf("No se ha encontrado\n");
}*/
