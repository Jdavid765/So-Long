/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcano-du <jcano-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:15:57 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/16 14:46:18 by jcano-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*curent;
	int		count;

	count = 0;
	curent = lst;
	if (curent == NULL)
		return (0);
	while (curent)
	{
		curent = curent->next;
		count++;
	}
	return (count);
}
/*#include <stdio.h>
int	main(void)
{
	int a = 12;
	t_list *head = ft_lstnew("david");
	t_list *second = ft_lstnew(&a);
	t_list *three = ft_lstnew("paul");
	head->next = second;
	second->next = three;
	int size = ft_lstsize(head);
	printf("%d\n", size);
}*/