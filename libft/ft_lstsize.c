/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:56:26 by made-jes          #+#    #+#             */
/*   Updated: 2024/11/04 19:15:35 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		lst = lst->next;
		counter++;
	}
	return (counter);
}

/*int main()
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = ft_lstnew("Node1");
	node2 = ft_lstnew("Node2");
	node3 = ft_lstnew("Node3");

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	printf("List size: %d\n", ft_lstsize(node1));
	free(node1);
    free(node2);
    free(node3);
    return 0;
}*/
