/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:25:31 by rpizpot           #+#    #+#             */
/*   Updated: 2019/06/24 17:25:31 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*inicialization(t_list *print, t_buf **buf)
{
	print->i = 0;
	print->flag = "-+ #0";
	print->typical_type = "cspdiouxXfe";
	print->size = "hlLjz";
	print->color = ft_memalloc(9);
	print->len = 0;
	(*buf)->i = 0;
	(*buf)->buf = ft_memalloc(BUFF_SIZE);
	(*buf)->for_space = 0;
	return (print);
}
