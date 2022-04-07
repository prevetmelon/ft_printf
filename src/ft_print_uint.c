/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <chandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:47:33 by chandsom          #+#    #+#             */
/*   Updated: 2021/01/31 19:21:15 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		strfree(char **str)
{
	if (*str)
		free(*str);
	*str = ft_strdup("");
}

static char	*ft_prepare_str(unsigned int d, t_kek *kek)
{
	char	*str;
	int		len;

	str = ft_itoa_u(d);
	len = (int)ft_strlen(str);
	if (kek->precision > len)
	{
		while ((kek->precision - len) > 0)
		{
			str = ft_strjoin_free("0", str);
			kek->precision--;
		}
	}
	if (kek->precision == -1 && kek->zero && kek->width != 0)
	{
		len = (int)ft_strlen(str);
		while (kek->width > len)
		{
			str = ft_strjoin_free("0", str);
			kek->width--;
		}
	}
	if (kek->precision == 0 && d == 0)
		strfree(&str);
	return (str);
}

int			ft_print_uint(va_list ap, t_kek *kek)
{
	unsigned int		d;
	char				*str;
	int					len;

	d = va_arg(ap, unsigned int);
	len = 0;
	str = ft_prepare_str(d, kek);
	if (kek->minus)
	{
		ft_putstr_fd(str, 1);
		len += (int)ft_strlen(str);
		len += fill_width(kek->width, (int)ft_strlen(str), 0);
	}
	else
	{
		len += fill_width(kek->width, (int)ft_strlen(str), 0);
		ft_putstr_fd(str, 1);
		len += (int)ft_strlen(str);
	}
	ft_strdel(&str);
	return (len);
}
