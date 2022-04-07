/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:38:56 by chandsom          #+#    #+#             */
/*   Updated: 2020/11/13 15:58:48 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t i2;

	i = 0;
	i2 = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[i2] && (i + i2 + 1) < dstsize)
	{
		dst[i + i2] = src[i2];
		i2++;
	}
	if (i < dstsize)
		dst[i + i2] = '\0';
	return (i + ft_strlen(src));
}
