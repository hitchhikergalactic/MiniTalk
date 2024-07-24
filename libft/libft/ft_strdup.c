/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:46:22 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 21:46:35 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	size;
	char			*copy;

	size = ft_strlen(s1) + 1;
	copy = malloc(size * sizeof(char));
	if (copy)
		ft_strlcpy(copy, s1, size);
	return (copy);
}
/*
int	main(void)
{
	char	*copy;

	copy = ft_strdup("Hola");
	printf("%s\n", copy);
	free(copy);
	return (0);
}*/
