/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <chandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:43:57 by chandsom          #+#    #+#             */
/*   Updated: 2021/01/31 20:24:10 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_kek	*ft_init(t_kek *kek)
{
	kek->type = 0;
	kek->width = 0;
	kek->minus = 0;
	kek->zero = 0;
	kek->precision = -1;
	return (kek);
}

char			*ft_kekflag(char *itr, t_kek *kek)
{
	while (*itr == '-' || *itr == '0')
	{
		if (*itr == '-')
			kek->minus = 1;
		if (*itr == '0')
			kek->zero = 1;
		itr++;
	}
	return (itr);
}

char			*ft_kekwidth(char *itr, int tmp, va_list ap, t_kek *kek)
{
	if (*itr == '*')
		kekzvezda(itr, tmp, ap, kek);
	else if (ft_isdigit(*itr))
	{
		tmp = ft_atoi(itr) * ((ft_atoi(itr) >= 0) - (ft_atoi(itr) < 0));
		if (ft_atoi(itr) < 0)
		{
			kek->minus = 1;
			kek->zero = 0;
		}
		kek->width = tmp;
		while (ft_isdigit(*itr))
			itr++;
	}
	return (itr);
}

char			*ft_parser(char *itr, va_list ap, t_kek *kek)
{
	int		len;
	int		tmp;

	len = 0;
	tmp = 0;
	kek = ft_init(kek);
	while (*itr)
	{
		itr = ft_kekflag(itr, kek);
		itr = ft_kekwidth(itr, tmp, ap, kek);
		itr = ft_prec_parse(itr, tmp, ap, kek);
		if (ft_strchr("cspdiuxX%", *itr))
		{
			kek->type = *itr;
			itr++;
			if (kek->minus == 1)
				kek->zero = 0;
			return (itr);
		}
		itr++;
	}
	return (itr);
}

void			ft_kekminus(char **itr, t_kek *kek)
{
	while (**itr == '-' || **itr == '0')
	{
		if (**itr == '-')
			kek->minus = 1;
		if (**itr == '0')
			kek->zero = 1;
		itr++;
	}
}
