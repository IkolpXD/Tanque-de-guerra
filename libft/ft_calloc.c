/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:13:50 by made-jes          #+#    #+#             */
/*   Updated: 2024/11/04 18:20:30 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;
	size_t	bytes;

	bytes = nmemb * size;
	if (size && ((bytes / size) != nmemb))
		return (NULL);
	tmp = malloc(bytes);
	if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, bytes);
	return (tmp);
}

/*int	main()
{
	int *arr;
	int	i;

	arr = (int *)ft_calloc(-5, -5);
	i = 0;
	while (i < -5)
	{
		printf("%d", arr[i]);
		i++;
	}
	printf("\n");
	free(arr);
	return (0);
}*/
