/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:01:53 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 22:02:10 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include <stdlib.h>
#include "../libft.h"

char	*ft_substr(const char	*s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	s_len;

	s_len = (unsigned int) ft_strlen(s);
	if (start > s_len)
	{
		sub = (char *)malloc (1);
		if (sub)
			sub [0] = '\0';
		return (sub);
	}
	if ((start + len) > s_len)
	{
		sub = (char *)malloc (((s_len - start) + 1) * sizeof(char));
		if (sub)
			ft_strlcpy (sub, (s + start), ((s_len - start) + 1));
		return (sub);
	}
	sub = (char *)malloc ((len +1) * sizeof(char));
	if (sub)
		ft_strlcpy (sub, (s + start), (len + 1));
	return (sub);
}
/*
int	main(void)
{
	char	*new_str;

	new_str = ft_substr ("Susana", 8, 5);
	printf("%s\n", new_str);
	new_str = ft_substr ("Susana Nunez", 6, 20);
	printf("%s\n", new_str);
	new_str = ft_substr ("Susana Nunez Zamora", 2, 8);
	printf("%s\n", new_str);
	free (new_str);
	return (0);
}*/
