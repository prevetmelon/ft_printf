/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <chandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:11:53 by chandsom          #+#    #+#             */
/*   Updated: 2020/11/19 14:48:34 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dst2;
	unsigned char *src2;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (src2 <= dst2 && (src2 != 0 && dst2 != 0))
		while (len--)
			dst2[len] = src2[len];
	else
		ft_memcpy(dst, src, len);
	return ((void *)dst);
	if (!dst && !src)
		return (NULL);
}
