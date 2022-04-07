/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <chandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:44:08 by chandsom          #+#    #+#             */
/*   Updated: 2021/01/28 18:16:06 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_char(va_list ap, t_kek *kek)
{
	int		len;
	char	c;

	c = va_arg(ap, int);
	len = 0;
	if (kek->minus)
	{
		ft_putchar_fd(c, 1);
		len++;
		len += fill_width(kek->width, 1, kek->zero);
	}
	else
	{
		len += fill_width(kek->width, 1, kek->zero);
		ft_putchar_fd(c, 1);
		len++;
	}
	return (len);
}
