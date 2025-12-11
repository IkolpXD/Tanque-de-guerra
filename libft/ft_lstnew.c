/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:13:58 by made-jes          #+#    #+#             */
/*   Updated: 2024/11/04 18:26:23 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*int main()
{
    char *lstnew_content;
    lstnew_content = "Vamos lá ver";

    t_list *new_node = ft_lstnew(lstnew_content);

    if (new_node)
    {
        printf("Node content: %s\n", (char *)new_node->content);
    }
    else
    {
        printf("Failed to create node\n");
    }
	return (0);
}*/
