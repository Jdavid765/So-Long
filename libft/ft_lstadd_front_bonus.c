/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcano-du <jcano-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:18:43 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/16 16:18:47 by jcano-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

/*#include <stdio.h>
int	main(void)
{
	//int a = 1212;
	//int b = 12;
	t_list *head = ft_lstnew("davidioooo");
	t_list *node = ft_lstnew("david");
	//ft_lstadd_front(&head, node);
	printf("%s", (char *) head -> content);
}*/