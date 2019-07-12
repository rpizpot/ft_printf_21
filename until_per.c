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
			while (j <= 8 && (*print)->copy[(*print)->i + j] != '%'
			&& (*print)->copy[(*print)->i + j] != '\0')
			{
				if (((*print)->copy[(*print)->i + j]) != '}')
					(*print)->color[j] = (*print)->copy[(*print)->i + j];
				else
				{
					(*print)->color[j] = (*print)->copy[(*print)->i + j];
					break ;
				}
				j++;
			}
			if (ft_color_print(*print))
				i -= 2;
			else
			{
				i += j - 1;
				ft_bzero((*print)->color, 9);
			}
			(*print)->i += j - 1;
		}
		i++;
		((*print)->i)++;
	}
	str = ft_strnew(i);
	((*print)->i) = ((*print)->i) - i - ft_strlen((*print)->color);
	i = 0;
	while ((*print)->copy[(*print)->i] != '%' && (*print)->copy[(*print)->i] != '\0')
	{
		if (ft_color_print(*print) && (*print)->copy[(*print)->i] == '{'
		&& !ft_strncmp((*print)->color, &((*print)->copy[(*print)->i]), ft_strlen((*print)->color)))
			((*print)->i) += ft_strlen((*print)->color);
		if ((*print)->copy[(*print)->i] != '%' && (*print)->copy[(*print)->i] != '\0')
			str[i++] = (*print)->copy[((*print)->i)++];
	}
	ft_bzero((*print)->color, 9);
	return (str);
}