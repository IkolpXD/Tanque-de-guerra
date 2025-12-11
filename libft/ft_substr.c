/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:15:25 by made-jes          #+#    #+#             */
/*   Updated: 2024/11/04 19:20:16 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		len_src;
	char		*substr;

	if (s == NULL)
		return (NULL);
	len_src = ft_strlen(s);
	if (start >= len_src)
		return (ft_calloc(1, 1));
	if (start + len > len_src)
		len = len_src - start;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len && start < len_src)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

/*int	main()
{
	char *s = "Olá, maluco.";
	unsigned int start = 5;
	size_t len = 10;

	printf("%s", ft_substr(s, start, len));
	free(s);
	return (0);
}*/
