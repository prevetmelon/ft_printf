/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <chandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:43:31 by chandsom          #+#    #+#             */
/*   Updated: 2020/11/19 20:04:40 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*str2;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
		return (NULL);
	while (s[i])
	{
		str2[i] = f(i, s[i]);
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
