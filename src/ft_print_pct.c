/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <chandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:45:44 by chandsom          #+#    #+#             */
/*   Updated: 2021/01/28 17:45:57 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_pct(va_list ap, t_kek *kek)
{
	int		len;

	(void)ap;
	len = 0;
	if (kek->minus)
	{
		ft_putchar_fd('%', 1);
		len++;
		len += fill_width(kek->width, 1, 0);
	}
	else
	{
		len += fill_width(kek->width, 1, kek->zero);
		ft_putchar_fd('%', 1);
		len++;
	}
	return (len);
}
