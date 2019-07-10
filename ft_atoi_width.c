/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 19:28:58 by rpizpot           #+#    #+#             */
/*   Updated: 2019/06/24 19:28:58 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_list *ft_atoi_width(t_list *print)
{
	if (print->copy[print->i] == '*')
	{
		print->width = va_arg(print->ap, unsigned int);
		print->i++;
		return (print);
	}
	while (print->copy[print->i] >= '0' && print->copy[print->i] <= '9')
	{
		print->width = print->width * 10 + (print->copy[print->i] - '0');
		print->i++;
	}
	return (print);
}