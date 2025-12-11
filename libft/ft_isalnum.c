/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:29:35 by made-jes          #+#    #+#             */
/*   Updated: 2024/10/30 17:42:06 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((ft_isdigit(c) || ft_isalpha(c)));
}

/*int	main()
{
	printf("%d\n", ft_isalnum('f'));
	printf("%d\n", ft_isalnum(127));
	printf("%d\n", ft_isalnum('d'));
	return (0);
}*/
