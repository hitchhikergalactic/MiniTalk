/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:59:34 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 22:00:03 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "../libft.h"

char	*ft_strnstr(const char	*haystack, const char	*needle, size_t len)
{
	size_t	index;
	size_t	equals;
	size_t	s2_len;

	if (*needle == 0)
		return ((char *)haystack);
	s2_len = ft_strlen(needle);
	index = 0;
	while (index < len && *haystack != '\0')
	{
		equals = ft_strncmp (haystack, needle, s2_len);
		if (equals == 0)
		{
			if ((len - index) < s2_len)
				return (0);
			else
				return ((char *)haystack);
		}
		haystack++;
		index++;
	}
	return (0);
}
/*
int	main(void)
{
	char	*result;

	result = ft_strnstr("Hola buena amiga", "buen", 12);
	printf("%s\n", result);
	result = ft_strnstr("Hola buena amiga", "", 100);
	printf("%s\n", result);
	result = ft_strnstr("Hola buena amiga", "ola", 3);
	printf("%ld\n",(long) result);
	result = ft_strnstr("Hola buena amiga", "Hola buena amiga", 16);
	printf("%s\n", result);
}*/
