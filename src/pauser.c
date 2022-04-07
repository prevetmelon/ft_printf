/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pauser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <chandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 20:23:15 by chandsom          #+#    #+#             */
/*   Updated: 2021/01/31 20:24:42 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_prec_parse(char *itr, int tmp, va_list ap, t_kek *kek)
{
	if (*itr == '.')
	{
		itr++;
		if (*itr == '*')
		{
			tmp = va_arg(ap, int);
			if (tmp < 0)
				tmp = -1;
			itr++;
			kek->precision = tmp;
		}
		else if (ft_isdigit(*itr))
		{
			kek->precision = ft_atoi(itr);
			while (ft_isdigit(*itr))
				itr++;
		}
		else
			kek->precision = 0;
	}
	return (itr);
}

void	kekzvezda(char *itr, int tmp, va_list ap, t_kek *kek)
{
	tmp = va_arg(ap, int);
	if (tmp < 0)
	{
		kek->minus = 1;
		tmp *= -1;
		kek->zero = 0;
	}
	kek->width = tmp;
	itr++;
}
