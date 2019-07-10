/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:39:02 by hlarson           #+#    #+#             */
/*   Updated: 2019/07/05 19:21:38 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hex(uintmax_t n, char a)
{
	char				*c;
	size_t				i;
	char				*x;

	c = (a == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
/*
 * Again this in buffer
	if (flag->precision == 0)
	{
		flag->octotorp = 0;
		return (ft_strdup(""));
	}
	if (n == 0)
	{
		flag->octotorp = 0;
		return (ft_strdup("0"));
	}
*/	
	i = count_numbers(n, 16) - 1;
	x = ft_strnew(i + 1);
	while (n)
	{
		x[i] = c[n % 16];
		n /= 16;
		i--;
	}
	return (x);
}

char	*ft_hex(t_list *print)
{
	uintmax_t	d;
	char		a;

	a = print->type;
	if (ft_strcmp(print->p_size, "") == 0)
		d = (uintmax_t)va_arg(print->ap, unsigned int);
	else if (ft_strcmp(print->p_size, "h") == 0)
		d = (uintmax_t)((char)va_arg(print->ap, unsigned int));
	else if (ft_strcmp(print->p_size, "ll") == 0)
		d = (uintmax_t)va_arg(print->ap, unsigned long long);
	else if (ft_strcmp(print->p_size, "hh") == 0)
		d = (uintmax_t)((short)va_arg(print->ap, unsigned int));
	else if (ft_strcmp(print->p_size, "l") == 0)
		d = (uintmax_t)va_arg(print->ap, unsigned long);
	else if (ft_strcmp(print->p_size, "z") == 0)
		d = (uintmax_t)va_arg(print->ap, size_t);
	else if (ft_strcmp(print->p_size, "j") == 0)
		d = (uintmax_t)va_arg(print->ap, uintmax_t);
	return (hex(d, a));
}
