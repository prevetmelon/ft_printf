/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kek_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <chandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:48:18 by chandsom          #+#    #+#             */
/*   Updated: 2021/01/28 17:48:24 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fill_width(int width, int minus, int zero)
{
	int		len;

	len = 0;
	while (width - minus > 0)
	{
		if (zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		len++;
		width--;
	}
	return (len);
}

int		fill_precision(char *str, int precision)
{
	int		len;

	len = 0;
	while (str[len] && len < precision)
	{
		ft_putchar_fd(str[len], 1);
		len++;
	}
	return (len);
}
