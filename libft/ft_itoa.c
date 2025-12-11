/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:13:58 by made-jes          #+#    #+#             */
/*   Updated: 2024/11/04 18:26:23 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	long int		num;

	num = n;
	len = ft_size(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = 48;
	str[len--] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		str[len--] = (num % 10) + 48;
		num /= 10;
	}
	return (str);
}

/*int	main()
{
	char	*result_itoa;

	result_itoa = ft_itoa(0);
	printf("%s\n", result_itoa);
	free(result_itoa);
	result_itoa = ft_itoa(1300);
	printf("%s\n", result_itoa);
	free(result_itoa);
	return (0);
}*/
