/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <chandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:01:29 by chandsom          #+#    #+#             */
/*   Updated: 2021/02/01 22:01:33 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	keksanya(t_kek **kek, int is_negative, int *len, char **str)
{
	if ((*kek)->precision == -1 && (*kek)->zero && (*kek)->width != 0)
	{
		if (is_negative)
			(*len)++;
		while ((*kek)->width > *len)
		{
			*str = ft_strjoin_free("0", *str);
			(*kek)->width--;
		}
		if (is_negative)
			*str = ft_strjoin_free("-", *str);
	}
	else if (is_negative)
		*str = ft_strjoin_free("-", *str);
}

static char	*ft_prepare_str(long long d, t_kek *kek)
{
	char	*str;
	int		is_negative;
	int		len;

	is_negative = 0;
	if (d < 0)
	{
		is_negative = 1;
		d *= -1;
	}
	str = ft_itoa(d);
	len = (int)ft_strlen(str);
	if (kek->precision > len)
	{
		while ((kek->precision - len) > 0)
		{
			str = ft_strjoin_free("0", str);
			kek->precision--;
		}
	}
	keksanya(&kek, is_negative, &len, &str);
	if (kek->precision == 0 && d == 0)
		strfree(&str);
	return (str);
}

int			ft_print_int(va_list ap, t_kek *kek)
{
	int		d;
	char	*str;
	int		len;

	d = va_arg(ap, int);
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
	free(str);
	return (len);
}
