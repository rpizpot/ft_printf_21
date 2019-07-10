/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:16:04 by hlarson           #+#    #+#             */
/*   Updated: 2019/07/05 19:17:58 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	ft_help_with_precision(char **d, int k)
{
	char	*x;
	char	*c;
	char	*a;
	char	*y;

	c = *d;
	x = ft_strjoin(ft_strdup("0."), ft_strnew_zero(k));
	a = ft_strjoin(x, ft_strdup("1"));
	y = ft_long_sum_dot(c, a);
	ft_strdel(&c);
	*d = y;
	ft_strdel(&a);
}

char	*ft_right_precision(char *c, int i)
{
	int		j;
	char	*d;
	int		k;

	k = i;
	d = ft_strnew(get_before_dot_float(c) + i + 2);
	j = 0;
	while (c[j] != '.')
	{
		d[j] = c[j];
		j++;
	}
	d[j] = c[j];
	while (i != -1)
	{
		j++;
		d[j] = c[j];
		i--;
	}
	if (c[j + 1] >= '5')
		ft_help_with_precision(&d, k);
	ft_strdel(&c);
	return (d);
}

char	*ft_pow_long_z(long long e, long long k)
{
	char		*c;
	char		*d;
	char		*x;

	d = ft_strdup("0.0");
	while (k > 0)
	{
		if (k & 1)
		{
			if (e - 52 < 0)
				c = ft_long_pow_minus(-(e - 52));
			else
				c = ft_long_pow(e - 52);
			x = ft_long_sum_dot(d, c);
			ft_strdel(&c);
			ft_strdel(&d);
			d = x;
		}
		k = k >> 1;
		e++;
	}
	return (d);
}

char	*ft_create_float(double d, int i)
{
	char			*c;
	long long		k;
	int				s;
	long long		e;
	int				j;

	i--;
	u_f.fl = d;
	s = (u_f.x & 0x8000000000000000) >> 63;
	u_f.x = u_f.x & 0x7FFFFFFFFFFFFFFF;
	e = ((u_f.x & 0x7FF0000000000000) >> 52) - 1023;
	k = (u_f.x & 0xfffffffffffff) | 0x10000000000000;
	c = ft_pow_long_z(e, k);
	j = get_after_dot_float(c);
	if (i == j)
		c = ft_strjoin(c, ft_strdup("0"));
	if (i > j)
		c = ft_strjoin(c, ft_strnew_zero(i - j + 1));
	if (i < j)
		c = ft_right_precision(c, i);
	c = (s == 1) ? ft_strjoin(ft_strdup("-"), c) : c;
	return (c);
}

char	*ft_float(t_list *print)
{
	double	d;
	int		i;

	i = 6;
	//Если 0, то удалить всё после точки
	if (print->precision == 0)
		return (ft_strdup("0"));
	if (ft_strcmp(print->p_size, "L") == 0)
		return (ft_long_double(print));
	d = va_arg(print->ap, double);
	if (print->precision != -1)
		i = print->precision;
	return (ft_create_float(d, i));
}
