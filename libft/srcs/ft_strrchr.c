/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <chandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:19:25 by chandsom          #+#    #+#             */
/*   Updated: 2020/11/12 18:58:59 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int count;

	count = ft_strlen(s) - 1;
	if (c == (int)NULL)
		return ((char *)&s[ft_strlen(s)]);
	while (count >= 0)
	{
		if (s[count] == c)
			return ((char *)&s[count]);
		count--;
	}
	return (NULL);
}
