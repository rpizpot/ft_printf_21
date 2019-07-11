/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:26:56 by rpizpot           #+#    #+#             */
/*   Updated: 2019/07/11 16:26:56 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_color_print(t_list *print)
{
	if (!ft_strcmp(print->color, "{red}"))
		return (1);
	if (!ft_strcmp(print->color, "{green}"))
		return (1);
	if (!ft_strcmp(print->color, "{yellow}"))
		return (1);
	if (!ft_strcmp(print->color, "{blue}"))
		return (1);
	if (!ft_strcmp(print->color, "{purple}"))
		return (1);
	if (!ft_strcmp(print->color, "{cyan}"))
		return (1);
	if (!ft_strcmp(print->color, "{eoc}"))
		return (1);
	return (0);
}