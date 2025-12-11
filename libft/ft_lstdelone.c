/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:56:26 by made-jes          #+#    #+#             */
/*   Updated: 2024/11/04 19:15:35 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*int	main()
{
	t_list	*node1 = malloc(sizeof(t_list));
	node1->content = ft_strdup("So FUNNY");

	printf("Before deleting node and content: %s\n", (char *)node1->content);
	ft_lstdelone(node1, free);
	node1 = NULL;
	if (node1 == NULL)
		printf("Sucess deleting node.\n");
	else
		printf("Failure.\n");
	return (0);
}*/
