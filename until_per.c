/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   until_per.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 21:10:18 by rpizpot           #+#    #+#             */
/*   Updated: 2019/07/07 21:10:18 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_until_per(t_list **print)
{
	int i;
	int j;
	char *str;

	i = 0;
	while ((*print)->copy[(*print)->i] != '%' && (*print)->copy[(*print)->i] != '\0')
	{
		if ((*print)->copy[(*print)->i] == '{')
		{
			j = 0;
			while (j <= 6 && ((*print)->copy[(*print)->i + j]) != '}')
			{
				(*print)->color[j] = (*print)->copy[(*print)->i + j];
				j++;
			}
			if (!ft_color_print(*print))
			{
				(*print)->i += j - 1;
				i += j - 1;
			}
		}
		i++;
		((*print)->i)++;
	}
	str = ft_strnew(i);
	((*print)->i) = ((*print)->i) - i;
	i = 0;
	while ((*print)->copy[(*print)->i] != '%' && (*print)->copy[(*print)->i] != '\0')
		str[i++] = (*print)->copy[((*print)->i)++];
	return (str);
}