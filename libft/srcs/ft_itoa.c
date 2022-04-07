/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <chandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:36:46 by chandsom          #+#    #+#             */
/*   Updated: 2021/01/29 23:30:05 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long long n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		if (n < 0)
		{
			n = n * -1;
			count++;
		}
		n = n / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(long long n)
{
	char	*str;
	int		count;
	int		negative;

	count = ft_count(n) + 1;
	negative = 1;
	if (n == 2147483648)
		return (ft_strdup("2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (!(str = (char *)malloc(sizeof(char) * count)))
		return (NULL);
	str[count - 1] = '\0';
	if (n < 0)
	{
		negative = -1;
		str[0] = '-';
	}
	while (count-- && n)
	{
		str[count - 1] = (n % 10 * negative) + '0';
		n = n / 10;
	}
	return (str);
}
