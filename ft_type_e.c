/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:29:02 by hlarson           #+#    #+#             */
/*   Updated: 2019/07/10 20:31:23 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_do_work(char *d, int j, int k, char a)
{
	char	*c;
	char    *number;

	c = ft_strnew(1);
	c[0] = a;
	number = ft_itoa(j);
	if (ft_strlen(number) == 1)
	    number = ft_strjoin(ft_strdup("0"), number);
	if (k == -1)
		d = ft_strjoin(ft_strjoin(ft_strjoin(d, c), ft_strdup("-")), number);
	else if (k == 1 || k == 0)
		d = ft_strjoin(ft_strjoin(ft_strjoin(d, c), ft_strdup("+")), number);
	return (d);
}



char    *ft_work(char *c, t_list *print, int precision)
{
    int     j;
    int     k;
    char    *d;
	char	*x;

    if ((j = (get_before_dot_float(c) - 1 )) > 1)
    {
        d = ft_remake_str(c);
        k = 1;
    }
	else if (c[1] == '.' && c[2] != '0')
        k = 0;
    else
	{
		j = ft_count_until_one(c);
		k = -1;
		d = ft_make_minus_str(c);
	}
    d = ft_make_precision(d, precision);
	x = ft_do_work(d, j, k, print->type);
	ft_strdel(&d);
	return (x);
}

static char	*ft_create_float(double d, int i, t_list *print)
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
    c = ft_work(c, print, i);
    c = (s == 1) ? ft_strjoin(ft_strdup("-"), c) : c;
    return (c);
}

char	*ft_type_e(t_list *print)
{
    double	d;
    int		i;

    i = 6;
    //Если 0, то удалить всё после точки
    if (print->precision == 0)
        return (ft_strdup("0"));
    if (ft_strcmp(print->p_size, "L") == 0)
        return (ft_type_e_l(print));
    d = va_arg(print->ap, double);
    if (print->precision != -1)
        i = print->precision;
    return (ft_create_float(d, i, print));
}
