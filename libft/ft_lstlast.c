/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:56:26 by made-jes          #+#    #+#             */
/*   Updated: 2024/11/04 19:15:35 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/*int main()
{
    t_list  *node1 = ft_lstnew("First");
    t_list  *node2 = ft_lstnew("Second");
    t_list  *node3 = ft_lstnew("Third");

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    t_list  *last_node = ft_lstlast(node1);
    if (last_node)
        printf("Last node in the list: %s\n", (char *)last_node->content);
    else
        printf("List is empty.\n");
    
    free(node1);
    free(node2);
    free(node3);
    return (0);
}*/
