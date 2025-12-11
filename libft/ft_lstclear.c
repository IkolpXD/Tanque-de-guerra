/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:56:26 by made-jes          #+#    #+#             */
/*   Updated: 2024/11/04 19:15:35 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		tmp = current;
		current = current->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}

/*void	del_content(void *content)
{
	free(content);
}

int	main()
{
	t_list	*start = malloc(sizeof(t_list));
	t_list	*node1 = malloc(sizeof(t_list));
	t_list	*node2 = malloc(sizeof(t_list));
	t_list	*node3 = malloc(sizeof(t_list));

	node1->content = ft_strdup("50");
	node2->content = ft_strdup("60");
	node3->content = ft_strdup("70");

	start->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	printf("Before clearing: %s\n", (char *)node1->content);
	ft_lstclear(&start, &del_content);
	if (start == NULL)
		printf("Sucess clearing the list.\n");
	else
		printf("Failure.\n");
	return (0);
}*/
