/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:34:01 by made-jes          #+#    #+#             */
/*   Updated: 2024/10/30 14:16:23 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*int	main()
{
	char arr[] = "try it out";
	size_t lenght = ft_strlen(arr);

	printf("Before ft_bzero: %s\n", arr);
	ft_bzero(arr, lenght);
	printf("After applying function: %s\n", arr);
	return (0);
}*/