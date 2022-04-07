/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <chandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:54:19 by chandsom          #+#    #+#             */
/*   Updated: 2020/11/12 18:43:43 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int count;

	count = 0;
	if (c == (int)NULL)
		return ((char *)&s[ft_strlen(s)]);
	while (s[count])
	{
		if (s[count] == c)
			return ((char *)&s[count]);
		count++;
	}
	return (NULL);
}
