/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcano-du <jcano-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:19:16 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/16 16:19:19 by jcano-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (!last)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}

/*#include <stdio.h>
int	main(void)
{
	t_list *head = ft_lstnew("la tete");
	t_list *second = ft_lstnew("le deuxieme");
	t_list *last = ft_lstnew("le dernier");
	t_list *lereallast = ft_lstnew("vraiment le dernier");
	head->next = second;
	second->next = last;
	last->next = lereallast;
	lereallast->next = NULL;
	t_list *result = ft_lstlast(head);
	printf("%s", (char *)result->content);
}*/