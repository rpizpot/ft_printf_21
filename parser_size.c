/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:04:18 by rpizpot           #+#    #+#             */
/*   Updated: 2019/06/25 16:04:18 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list *parser_size(t_list *print)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (print->size[i])
	{
		if (print->copy[print->i] == print->size[i])
		{
			print->p_size[j] = print->copy[print->i];
			j++;
			print->i++;
			i = -1;
		}
		i++;
	}
	return (print);
}