/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:56:26 by made-jes          #+#    #+#             */
/*   Updated: 2024/11/04 19:15:35 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*int main()
{
    t_list  *node1 = ft_lstnew("First");
    t_list  *node2 = ft_lstnew("Second");
    t_list  *node3 = ft_lstnew("Third");

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    t_list  *node_to_add = ft_lstnew("New Node");

    ft_lstadd_front(&node1, node_to_add);
    t_list *current = node1;
    while (current)
    {
        printf("%s -> ", (char *)current->content);
        current = current->next;
    }
	printf("NULL\n");
    return (0);
}*/