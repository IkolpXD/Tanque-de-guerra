/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:52:48 by made-jes          #+#    #+#             */
/*   Updated: 2025/03/04 12:24:15 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	bytes_read = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (*buff || bytes_read > 0)
	{
		if (!*buff)
		{
			bytes_read = handle_read(fd, buff);
			if (bytes_read < 0)
				return (free(line), NULL);
			if (bytes_read == 0)
				break ;
		}
		line = ft_strjoin1(line, buff);
		if (ft_newline(buff))
			break ;
	}
	return (line);
}
