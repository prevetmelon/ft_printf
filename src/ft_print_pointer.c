/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <chandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:01:43 by chandsom          #+#    #+#             */
/*   Updated: 2021/02/01 22:01:45 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen_base(unsigned long d)
{
	int counter;

	counter = 0;
	while (d != 0)
	{
		d /= 16;
		counter++;
	}
	return (counter);
}

static char	*sanyas_kek(unsigned long buf, char *str, int counter)
{
	str[counter] = '\0';
	counter--;
	while (buf != 0)
	{
		if (buf % 16 < 10)
			str[counter] = buf % 16 + 48;
		else
			str[counter] = buf % 16 + 87;
		buf /= 16;
		counter--;
	}
	return (str);
}

static void	sanya_kek(t_kek **kek, int *len, char **str)
{
	if ((*kek)->minus == 0)
	{
		*len += fill_width((*kek)->width, ft_strlen(*str) + 2, (*kek)->zero);
		*len += fill_precision("0x", 2);
		if ((*kek)->precision >= 0)
		{
			*len += fill_width((*kek)->precision - 1, ft_strlen(*str),
(*kek)->zero) + fill_precision(*str, (*kek)->precision);
		}
		else
			*len += fill_precision(*str, ft_strlen(*str));
	}
	else
	{
		*len += fill_precision("0x", 2);
		if ((*kek)->precision >= 0)
		{
			*len += fill_width((*kek)->precision - 1,
ft_strlen(*str), (*kek)->zero);
			*len += fill_precision(*str, (*kek)->precision);
		}
		else
			*len += fill_precision(*str, ft_strlen(*str));
		*len += fill_width((*kek)->width, ft_strlen(*str) + 2, (*kek)->zero);
	}
}

int			zeroprecision(t_kek *kek)
{
	int	len;

	len = 0;
	ft_putstr_fd("0x", 1);
	len += 2;
	len += fill_width(kek->width, 0, 1);
	return (len);
}

int			ft_print_pointer(va_list ap, t_kek *kek)
{
	int				len;
	int				counter;
	char			*str;
	unsigned long	d;
	unsigned long	buf;

	d = va_arg(ap, unsigned long);
	len = 0;
	buf = d;
	if (d == 0 && kek->precision == 0)
		len = zeroprecision(kek);
	else
	{
		if (d == 0)
			str = ft_strdup("0");
		else
		{
			counter = ft_strlen_base(d);
			str = (char *)malloc(sizeof(char) * (counter + 1));
			str = sanyas_kek(buf, str, counter);
		}
		sanya_kek(&kek, &len, &str);
		free(str);
	}
	return (len);
}
