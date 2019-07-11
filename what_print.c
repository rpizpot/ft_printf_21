/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:49:14 by rpizpot           #+#    #+#             */
/*   Updated: 2019/06/25 17:49:14 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void what_print(t_list *print, t_buf *for_buf)
{
	if (print->type == 'd' || print->type == 'i')
		buffer(print, for_buf, ft_int(print));
	else if (print->type == 'o')
		buffer(print, for_buf, ft_octal(print));
	else if (print->type  == 'X' || print->type == 'x')
		buffer(print, for_buf, ft_hex(print));
	else if (print->type  == 'u')
		buffer(print, for_buf, ft_unsigned_int(print));
	else if (print->type == 'f')
		buffer(print, for_buf, ft_float(print));
	else if (print->type == 'e' || print->type == 'E')
	    buffer(print, for_buf, ft_type_e(print));
}