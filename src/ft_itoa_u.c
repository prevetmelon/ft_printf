/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <chandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:43:33 by chandsom          #+#    #+#             */
/*   Updated: 2021/01/30 00:05:06 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned long long n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa_u(unsigned long long n)
{
	char				*str;
	int					count;
	unsigned int		i;
	int					negative;

	count = ft_count(n) + 1;
	i = n;
	if (n == 4294967295)
		return (ft_strdup("4294967295"));
	negative = 1;
	if (!(str = (char *)malloc(sizeof(char) * count)))
		return (NULL);
	if (n == 0)
		str[count - 2] = '0';
	str[count - 1] = '\0';
	while (count-- && n)
	{
		i = n % 10;
		n = n / 10;
		str[count - 1] = i + '0';
	}
	return (str);
}
