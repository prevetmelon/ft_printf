/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:07:11 by chandsom          #+#    #+#             */
/*   Updated: 2020/11/12 18:41:27 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	i;

	i = 0;
	s1 = (unsigned char *)s;
	while (i < n && s1[i] != (unsigned char)c)
		i++;
	if (i == n)
		return (NULL);
	return ((void *)&s1[i]);
}
