/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcano-du <jcano-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:02:16 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/17 11:10:10 by jcano-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*curent;

	curent = lst;
	while (curent)
	{
		f(curent->content);
		curent = curent->next;
	}
}

/*void fchange(void *content)
{
	*(int *)content = *(int *)content * 2;
}

#include <stdio.h>
int	main(void)
{
	void(*f)(void *);
	f = &fchange;
	int a = 2;
	int b = 4;
	t_list *head = ft_lstnew(&a);
	t_list *second = ft_lstnew(&b);
	head->next = second;
	second->next = NULL;
	ft_lstiter(head,f);
	t_list *result = head;
	while(result)
	{
		printf("%d\t", *(int *)result->content);
		result = result->next;
	}
}*/