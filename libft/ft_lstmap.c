/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:56:26 by made-jes          #+#    #+#             */
/*   Updated: 2024/11/04 19:15:35 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*void	*uppercase(void *content)
{
	char	*str = (char *)content;
	size_t	len = ft_strlen(str);
	char	*new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	size_t i = 0;
	while (i < len)
	{
		new_str[i] = str[i] - 32;
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}

void del_content(void *content)
{
    free(content);
}

int	main()
{
	t_list	*node1 = malloc(sizeof(t_list));
	t_list	*node2 = malloc(sizeof(t_list));
	t_list	*node3 = malloc(sizeof(t_list));

	node1->content = ft_strdup("first");
	node2->content = ft_strdup("second");
	node3->content = ft_strdup("third");

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	t_list *before = node1;
    while (before)
    {
        printf("Before function: %s\n", (char *)before->content);
        before = before->next;
    }
	t_list	*new_list = ft_lstmap(node1, uppercase, del_content);
	t_list	*current = new_list;
	while (current)
	{
		printf("Content after function: %s\n", (char *)current->content);
		current = current->next;
	}
	ft_lstclear(&node1, &del_content);
	ft_lstclear(&new_list, &del_content);
	return (0);
}*/
