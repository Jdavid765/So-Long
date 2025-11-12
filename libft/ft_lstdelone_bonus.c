/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcano-du <jcano-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:52:40 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/17 10:58:38 by jcano-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!(lst || del))
		return ;
	del(lst->content);
	free(lst);
}

/*void delete(void *content)
{
	free(content);
}

#include <stdio.h>
int	main(void)
{
	void (*del) (void *);
	del = &delete;
	t_list *head = ft_lstnew(ft_strdup("david"));
	t_list *second = ft_lstnew(ft_strdup("paul"));
	t_list *three = ft_lstnew(ft_strdup("intrus"));
	head->next = three;
	three->next = NULL;
	ft_lstdelone(second,del);
	t_list *list = head;
	while (list)
	{
		printf("%s",(char *)list->content);
		list = list->next;
	}
}*/