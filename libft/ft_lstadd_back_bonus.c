/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcano-du <jcano-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:19:32 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/16 16:19:35 by jcano-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

/*#include <stdio.h>
int	main(void)
{
	t_list *head = ft_lstnew("david");
	t_list *second = ft_lstnew("paul");
	t_list *three = ft_lstnew("Roberto");
	t_list *new = ft_lstnew("le dernier des dernier");
	head->next = second;
	second->next = three;
	three->next = NULL;
	ft_lstadd_back(&head, new);
	t_list *tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	printf("%s", (char *)tmp->content);
}*/