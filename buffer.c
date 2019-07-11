/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:35:03 by rpizpot           #+#    #+#             */
/*   Updated: 2019/07/04 17:35:03 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buf *filling_buf(t_list *print, t_buf *for_buf, char **str)
{
	if (print->plus != '+' && print->space == ' ' && (print->type == 'd'
			|| print->type == 'i' || print->type == 'f'))
		if (!((*str)[0] == '-'))
			for_buf->buf[for_buf->i++] = ' ';
	if (print->plus == '+' && (print->type == 'd' || print->type == 'i'
	|| print->type == 'f'))
		if (!((*str)[0] == '-'))
			for_buf->buf[for_buf->i++] = '+';
	if ((*str)[0] == '-')
	{
		(*str)++;
		for_buf->buf[for_buf->i++] = '-';
		if (print->precision > 0)
			for_buf->len--;
	}
	if (print->lattice == '#' && print->type == 'o')
	{
		for_buf->buf[for_buf->i++] = '0';
		for_buf->len++;
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
	if ((int)(print->precision - for_buf->len) > 0)
		while ((int)(print->precision - for_buf->len) > 0)
		{
			for_buf->buf[for_buf->i++] = '0';
			for_buf->len++;
		}
	return (for_buf);
}

t_buf *filling_buf_str(t_buf *for_buf, char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		for_buf->buf[for_buf->i] = str[i];
		if (for_buf->i == BUFF_SIZE)
		{
			write(1, for_buf->buf, for_buf->i);
			ft_strdel(&for_buf->buf);
			for_buf->buf = ft_memalloc(BUFF_SIZE);
			for_buf->i = -1;
		}
		i++;
		for_buf->i++;
	}
	return (for_buf);
}

t_buf *filling_buf_byspace(t_list *print, t_buf *for_buf)
{
	size_t i;

	i = 0;
	if (print->zero == '0' && print->precision > 0 && (print->type == 'd'
	|| print->type == 'i' || print->type == 'o' || print->type == 'x'
	|| print->type == 'X'))
		print->zero = ' ';
	if (print->minus == '-')
		print->zero = ' ';
	if ((for_buf->sign == '+' || for_buf->sign == '-') && print->zero == '0')
	{
		for_buf->buf[for_buf->i++] = for_buf->sign;
		for_buf->len--;
	}
	while (((int)(print->width - for_buf->len - for_buf->for_space - i)) > 0)
	{
		for_buf->buf[for_buf->i] = print->zero;
		if (for_buf->i == BUFF_SIZE)
		{
			write(1, for_buf->buf, for_buf->i);
			ft_strdel(&for_buf->buf);
			for_buf->buf = ft_memalloc(BUFF_SIZE);
			for_buf->i = -1;
		}
		i++;
		for_buf->i++;
	}
	return (for_buf);
}

t_buf  *buffer(t_list *print, t_buf *for_buf, char *str)
{

	for_buf->len = ft_strlen(str);
	if (print->minus == '-')
	{
		filling_buf(print, for_buf, &str);
		filling_buf_str(for_buf, str);
		filling_buf_byspace(print, for_buf);
	}
	else
	{
		filling_buf_2(print, for_buf, &str);
		filling_buf_byspace(print, for_buf);
		filling_buf_start(print, for_buf, ft_strlen(str));
		filling_buf_str(for_buf, str);
	}
	return (for_buf);
}