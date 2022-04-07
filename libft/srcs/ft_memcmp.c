/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:35:30 by chandsom          #+#    #+#             */
/*   Updated: 2020/11/12 18:55:43 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s21;
	size_t			i;

	s11 = (unsigned char *)s1;
	s21 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s11[i] != s21[i])
			return (s11[i] - s21[i]);
		i++;
	}
	return (0);
}
