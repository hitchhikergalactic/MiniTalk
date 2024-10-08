/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:57:33 by osredond          #+#    #+#             */
/*   Updated: 2024/07/16 20:57:47 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

t_list	*ft_lstlast(t_list	*lst)
{
	t_list	*last;

	last = NULL;
	while (lst != NULL)
	{
		last = lst;
		lst = lst->next;
	}
	return (last);
}
/*
int	main(void)
{
	t_list	*node;
	t_list *node2;
	t_list *node3;
	t_list *last;

	last = ft_lstlast(NULL);
	printf("%ld\n", (long)last);
	
	node = ft_lstnew (1);
	last = ft_lstlast(node);
	printf("%d\n", last->content);

	node2 = ft_lstnew (2);
	ft_lstadd_front(node, node2);
	last = ft_lstlast(node2);
	printf("%d\n", last->content);
	last = ft_lstlast(node);
	printf("%d\n", last->content);

	node3 = ft_lstnew (3);
	ft_lstadd_front(node2, node3);
	last = ft_lstlast(node3);
	printf("%d\n", last->content);
	last = ft_lstlast(node2);
	printf("%d\n", last->content);
	last = ft_lstlast(node);
	printf("%d\n", last->content);
	return (0);
}*/
