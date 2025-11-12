/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcano-du <jcano-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:37:01 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/17 10:51:46 by jcano-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = ((*lst)->next);
		ft_lstdelone(tmp, del);
	}
	*lst = NULL;
}

/*#include <stdio.h>
void delete(void *content) 
{
	 free(content); 
}
int	main(void) 
{
    printf("Test ft_lstclear:\n");
	void (*del)(void *);
	del = &delete;
    t_list *lst = ft_lstnew(ft_strdup("one"));
    ft_lstclear(&lst, del);
	if (lst == NULL)
    printf("lst is NULL after clear\n");
	else
    printf("lst is not NULL\n");
}*/