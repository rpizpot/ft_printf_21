/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_right_alignment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 18:20:59 by rpizpot           #+#    #+#             */
/*   Updated: 2019/07/05 18:20:59 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buf *filling_buf_2(t_list *print, t_buf *for_buf, char **str)
{
	if (print->plus != '+' && print->space == ' ' && (print->type == 'd'
			|| print->type == 'i'))
		if (!(str[0] == '-'))
			for_buf->for_space = 1;
	if (print->plus == '+' && (print->type == 'd' || print->type == 'i'
	|| print->type == 'f'))
		if (!(str[0] == '-'))
		{
			for_buf->sign = '+';
			for_buf->for_space = 1;
		}
	if ((*str)[0] == '-')
	{
		for_buf->sign = '-';
		for_buf->for_space = 1;
		(*str)++;
	}
	if (print->lattice == '#' && print->type == 'o')
	{
		for_buf->for_space = 1;
		for_buf->len++;
	}
	else if (print->lattice == '#' && print->type == 'x')
		for_buf->for_space = 2;
	else if (print->lattice == '#' && print->type == 'X')
		for_buf->for_space = 2;
	if ((int)(print->precision - for_buf->len) > 0)
		for_buf->len += (int)(print->precision - for_buf->len);
		return (for_buf);
}

t_buf *filling_buf_start(t_list *print, t_buf *for_buf, int len)
{
	if (print->zero != '0')
	{
		if (for_buf->sign == '-')
			for_buf->buf[for_buf->i++] = for_buf->sign;
		else if (for_buf->for_space && print->plus == '+')
			for_buf->buf[for_buf->i++] = for_buf->sign;
	}
	if (for_buf->for_space && print->space == ' ' && !for_buf->sign)
		for_buf->buf[for_buf->i++] = ' ';
	else if (print->lattice == '#' && print->type == 'o')
	{
		for_buf->buf[for_buf->i++] = '0';
		len++;
	}
	else if (print->lattice == '#' && print->type == 'x')
	{
		for_buf->buf[for_buf->i++] = '0';
		for_buf->buf[for_buf->i++] = 'x';
	}
	else if (print->lattice == '#' && print->type == 'X')
	{
		for_buf->buf[for_buf->i++] = '0';
		for_buf->buf[for_buf->i++] = 'X';
	}
	while ((int)(print->precision - len) > 0)
	{
		for_buf->buf[for_buf->i++] = '0';
		len++;
	}
	return (for_buf);
}