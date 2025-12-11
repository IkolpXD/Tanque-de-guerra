/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:43:10 by made-jes          #+#    #+#             */
/*   Updated: 2024/10/30 14:19:41 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int		i;

	if (!*s)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}

static size_t	ft_next_word_len(char const **s, char c)
{
	size_t	len;

	len = 0;
	while (**s == c && **s)
		(*s)++;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	return (len);
}

static void	ft_free_split(char **lst, int i)
{
	while (i >= 0)
	{
		free(lst[i]);
		i--;
	}
	free(lst);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	len;
	int		i;

	if (!s)
		return (NULL);
	lst = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!lst)
		return (NULL);
	i = 0;
	while (*s)
	{
		len = ft_next_word_len(&s, c);
		if (len > 0)
		{
			lst[i] = (ft_substr(s, 0, len));
			if (!lst[i++])
				return (ft_free_split(lst, i - 1), NULL);
			s += len;
		}
	}
	lst[i] = NULL;
	return (lst);
}

/*int	main()
{
	char const	*str = "Uma frase qualquer, disse ela numa noite tipica";
	char		demilitator = ' ';
	char		**result = ft_split(str, demilitator);
    int			i;

    i = 0;
    while (result[i] != NULL)
	{
        printf("Print: %s\n", result[i]);
        i++;
    }
	while (result[i])
	{
		free(result[i]);
	}
	free(result);
}*/
