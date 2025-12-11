/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:30:41 by made-jes          #+#    #+#             */
/*   Updated: 2024/10/30 16:31:46 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t	len;
	size_t	j;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	j = 0;
	while (src[j] && j < size - 1)
	{
		dest[j] = src[j];
		j++;
	}
	if (size > 0)
		dest[j] = '\0';
	return (len);
}

/*int	main()
{
	char	src[] = "hello";
	char	dest[3] = "";
	unsigned int	result = ft_strlcpy(dest, src, 3);
	
	printf("Result lenght: %u\n", result);
	printf("Destination string, %s\n", dest);
	return (0);
}*/
