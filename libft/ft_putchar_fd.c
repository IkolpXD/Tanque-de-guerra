/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:47:00 by made-jes          #+#    #+#             */
/*   Updated: 2024/11/04 18:20:54 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*int	main()
{
	char	c = 'A';
	int	fd = STDOUT_FILENO;

	ft_putchar_fd(c, fd);
	printf("\n");
	return (0);
}*/

/*int	main()
{
	int fd_putchar = open("fd_teste.txt", O_CREAT | S_IRWXU | O_WRONLY );
        if (fd_putchar == -1) 
		return ("not open");
	else
	        printf("Ficheiro criado com sucesso\n\n");
	ft_putchar_fd('C', fd_putchar);
	ft_putchar_fd('\n', fd_putchar);
	close(fd_putchar);
}*/
