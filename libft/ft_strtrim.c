/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:59:17 by made-jes          #+#    #+#             */
/*   Updated: 2024/11/04 19:04:21 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen((char *)s1) - 1;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup((char *)s1));
	while (s1[start] && (ft_strchr(set, s1[start])))
		start++;
	while (end >= start && (ft_strchr(set, s1[end])))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}

/*int	main()
{
	 char *result;

	 result = ft_strtrim("   xxxtripouille   xxx", " x");
	 printf("Test - Result: %s\n", result);
	 free(result);

	 result = ft_strtrim("abcdba", "acb");
	 printf("Test - Result: %s\n", result);
	 free(result);

    return 0;
}*/
