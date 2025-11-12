/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcano-du <jcano-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:09:21 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/16 22:20:04 by jcano-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*head;
	t_list	*current;
	void	*new;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	head = NULL;
	while (lst)
	{
		new = f(lst->content);
		current = ft_lstnew(new);
		if (!current)
		{
			del(new);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, current);
		lst = lst->next;
	}
	return (head);
}
/*void *fchange(void *content)
{
    char *str = (char *)content;
    size_t len = ft_strlen(str);
    char *new_str = malloc(len + 2);
    if (!new_str)
        return NULL;
    strcpy(new_str, str);
    new_str[len] = '!'; // Ajoute un caractère
    new_str[len + 1] = '\0';
    return new_str;
}
void delete(void *content)
{
	free(content);
}

#include <stdio.h>
int	main(void)
{
	void *(*f)(void *);
	f = &fchange;
	void (*del)(void *);
	del = &delete;
	//int a = 2;
	//int b = 4;
	//int c = 8;
	//int d = 10;
	//int e = 20;
	t_list *head = ft_lstnew("david");
	t_list *second = ft_lstnew("paul");
	t_list *three = ft_lstnew("sebastien");
	t_list *four = ft_lstnew("jean");
	t_list *five = ft_lstnew("jean2");
	head->next = second;
	second->next = three;
	three->next = four;
	four->next = five;
	five->next = NULL;
	t_list *result = ft_lstmap(head,f,del);
	while (result)
	{
		printf("%s\t", (char *)result->content);
		result = result->next;
	}
}*/