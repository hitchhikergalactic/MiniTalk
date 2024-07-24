/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:48:44 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 21:49:09 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"
/*
void ft_new_toupper(unsigned int index, char *s)
{
	(void) index;
	*s = ft_toupper(*s);
}

void	ft_new_tolower(unsigned int index, char *s)
{
	(void) index;
	*s = ft_tolower (*s);
}

void	ft_new_isspace(unsigned int index, char *s)
{
	(void) index;
	if ((*s == '\t') || (*s == '\n') || (*s == '\f') || (*s == '\r')
		|| (*s == ' ') || (*s == 11))
	*s = '0';
}

void convert_to_underscore(unsigned int index, char *s)
{
	(void) index;
	if (*s == '_')
	*s = ' ';
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		(*f)(index, &(s[index]));
		index++;
	}
}
/*
int	main(void)
{
	char str[] = " hola_ muchachita  LINDA";
	ft_striteri(str, ft_new_toupper);
	printf("%s\n", str);
	
	ft_striteri(str, ft_new_tolower);
	printf("%s\n", str);
	
	ft_striteri(str, ft_new_isspace);
	printf("%s\n", str);
	
	ft_striteri(str, convert_to_underscore);
	printf("%s\n", str);
	return(0);
}*/
