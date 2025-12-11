/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:24:14 by made-jes          #+#    #+#             */
/*   Updated: 2024/10/30 18:30:52 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*new_str;
	int		i;
	int		lenght;

	lenght = ft_strlen(src);
	new_str = ((char *) malloc(sizeof(char) * (lenght + 1)));
	i = 0;
	if (!new_str)
		return (NULL);
	while (src[i] && i < lenght)
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/*int	main()
{
	char	*str = "Hello";

	printf("Original: %s\n", str);
	printf("Duplicada: %s\n", ft_strdup(str));
	return (0);
}*/