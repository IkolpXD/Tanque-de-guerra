/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:41:26 by made-jes          #+#    #+#             */
/*   Updated: 2024/10/30 14:15:16 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*p = (unsigned char)c;
		p++;
		n--;
	}
	return (s);
}

/*int	main()
{
	char	buffer[10];
	
	ft_memset(buffer, 'M', sizeof(buffer) - 1);
	buffer[9] = '\0';
	
	printf("Buffer inicial: %s\n", buffer);
	ft_memset(buffer, 'I', 5);
	printf("Buffer final: %s\n", buffer);
	return (0);
}*/
