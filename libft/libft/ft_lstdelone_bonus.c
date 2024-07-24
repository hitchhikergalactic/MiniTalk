/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:55:43 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 20:56:00 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"
#include <string.h>

/*
static void ft_free_itoa(void *content)
{
	free(content);
}
*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del != NULL)
		(*del)(lst->content);
	free(lst);
}

/*
int main(void)
{
	t_list *list;

	list = ft_lstnew(ft_itoa(0));
	ft_lstdelone(list, ft_free_itoa);

	list = ft_lstnew("hola");
	ft_lstdelone(list, NULL);

	return (0);
}
*/
