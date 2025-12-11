/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:34:54 by made-jes          #+#    #+#             */
/*   Updated: 2024/10/30 17:42:21 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	size_t			i;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/*int	main()
{
	char	str[] = "Bom dia";
	int	c = 'd';
	char *result = ft_memchr(str, c, 7);
	char *result1 = memchr(str, c, 7);
	
	printf("%s\n", result);
	printf("%s\n", result1);
	return (0);
}*/
