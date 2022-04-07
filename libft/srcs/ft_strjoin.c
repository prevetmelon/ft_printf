/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <chandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:38:18 by chandsom          #+#    #+#             */
/*   Updated: 2021/01/31 20:51:41 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **s)
{
	free(*s);
	*s = NULL;
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char *result;

	result = ft_strjoin(s1, s2);
	ft_strdel(&s2);
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dst;
	unsigned int	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	dst = (char*)malloc(sizeof(*dst) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	while (*s1 != '\0')
		dst[i++] = *s1++;
	while (*s2 != '\0')
		dst[i++] = *s2++;
	dst[i] = '\0';
	return (dst);
}
