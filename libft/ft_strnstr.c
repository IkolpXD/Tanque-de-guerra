/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:08:56 by made-jes          #+#    #+#             */
/*   Updated: 2024/10/30 18:18:42 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && (i + j < len))
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

//#include <bsd/string.h>

/*int	main()
{
	const char big[30] = "aaabcabcd";
	const char little[10] = "abc";
	size_t	len = 40;
	
	printf("%s\n", ft_strnstr(big, "cd", 8));
	printf("%s\n", strnstr(big, "cd", 8));
	return (0);
}*/
