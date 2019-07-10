/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 19:57:12 by rpizpot           #+#    #+#             */
/*   Updated: 2019/05/17 21:29:00 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	t_list *print;
	t_buf  *for_buf;

	if(!(print = (t_list *)malloc(sizeof(t_list))))
		return (0);
	print->copy = format;
	if(!(for_buf = (t_buf *)malloc(sizeof(t_buf))))
		return (0);
	inicialization(print, &for_buf);
	va_start(print->ap, format);
	while(print->copy[print->i])
	{
		if (print->copy[print->i] == '%')
		{
			parser(print, for_buf);
			print->i++;
		}
		else
		{
			reinicialization(print, &for_buf);
			buffer(print, for_buf, ft_until_per(&print));
		}
	}
	va_end(print->ap);
	write(1, for_buf->buf, for_buf->i);
	/*while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				ft_printf_c(va_arg(ap, char));
			if(*format == 's')
				ft_printf_s(va_arg(ap, char *));
			if (*format == 'p')
				ft_printf_p((long int)va_arg(ap, void *));
		}
		ft_printf_c(*format);
		format++;
	}
	va_end(ap);*/
}