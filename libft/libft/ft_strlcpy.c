/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:54:51 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 21:54:57 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "../libft.h"

size_t	ft_strlcpy(char	*dst, const char	*src, size_t	dstsize)
{
	size_t	index;

	index = 0;
	if (src[index] == '\0')
	{
		dst[index] = '\0';
		return (0);
	}
	if (dstsize == 0)
		return (ft_strlen (src));
	while (src[index] != '\0' && index < (dstsize -1))
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char	buffer[0];
 	int		len;

	len = ft_strlcpy (buffer, "Hola", 3);
	printf ("%d\n", len);
	printf("%s", buffer);
	return (0);
}*/
