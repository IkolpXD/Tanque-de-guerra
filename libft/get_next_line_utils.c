/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:52:48 by made-jes          #+#    #+#             */
/*   Updated: 2025/03/17 21:39:13 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	handle_read(int fd, char *buff)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buff, BUFFER_SIZE);
	if (bytes_read < 0)
		buff[0] = '\0';
	else if (bytes_read > 0)
		buff[bytes_read] = '\0';
	return (bytes_read);
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin1(char *line, char *buff)
{
	char	*result;
	size_t	i;
	size_t	j;

	result = malloc(ft_strlen_gnl(line) + ft_strlen(buff) + 1);
	if (!result)
		return (free(line), NULL);
	i = 0;
	while (line && line[i])
	{
		result[i] = line[i];
		i++;
	}
	free(line);
	j = 0;
	while (buff[j])
	{
		result[i++] = buff[j];
		if (buff[j++] == '\n')
			break ;
	}
	result[i] = '\0';
	return (result);
}

int	ft_newline(char *buff)
{
	char	*newline;
	size_t	i;

	newline = ft_strchr1(buff, '\n');
	if (newline)
	{
		i = 0;
		newline++;
		while (*newline)
			buff[i++] = *newline++;
		buff[i] = '\0';
		return (1);
	}
	i = 0;
	while (buff[i])
		buff[i++] = 0;
	return (0);
}

char	*ft_strchr1(char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return (NULL);
}
