/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:21:46 by made-jes          #+#    #+#             */
/*   Updated: 2024/11/05 18:48:30 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;

	i = 0;
	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	if (size == 0)
		return (len_s);
	if (len_d >= size)
		return (len_s + size);
	while (src[i] && i < (size - len_d - 1))
	{
		dest[len_d + i] = src[i];
		i++;
	}
	dest[len_d + i] = 0;
	return (len_d + len_s);
}

/*int	main(void)
{
	char dest[10] = "A";
	char *src = "ABCD";
	
	printf("Result: %zu\n", ft_strlcat(dest, src, 0));
	//printf("Destination string: %s\n", dest);
	return (0);
}*/
