/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <chandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:01:55 by chandsom          #+#    #+#             */
/*   Updated: 2021/02/02 02:56:34 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct	s_kek
{
	char		type;
	int			width;
	int			minus;
	int			zero;
	int			precision;
}				t_kek;

char			*ft_itoa_u(unsigned long long n);
char			*ft_parser(char *itr, va_list ap, t_kek *kek);
int				ft_printf(const char *format, ...);
int				ft_print_char(va_list ap, t_kek *kek);
int				fill_width(int width, int minus, int zero);
int				ft_decider(va_list ap, t_kek *kek);
int				ft_print_string(va_list ap, t_kek *kek);
int				ft_print_pct(va_list ap, t_kek *kek);
int				ft_print_int(va_list ap, t_kek *kek);
int				ft_print_uint(va_list ap, t_kek *kek);
int				ft_print_pointer(va_list ap, t_kek *kek);
int				fill_precision(char *str, int precision);
int				ft_print_x(va_list ap, t_kek *kek);
void			strfree(char **str);
char			*ft_prec_parse(char *itr, int tmp, va_list ap, t_kek *kek);
void			kekzvezda(char *itr, int tmp, va_list ap, t_kek *kek);

#endif
