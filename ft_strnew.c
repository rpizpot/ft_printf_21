/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 00:17:40 by rpizpot           #+#    #+#             */
/*   Updated: 2019/04/11 16:39:59 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
char	*ft_strnew(size_t size)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (size == (size_t)-1)
		return (NULL);
	new_str = malloc(sizeof(char) * size + 1);
	if (new_str)
	{
		while (i <= size)
		{
			new_str[i] = 0;
			i++;
		}
		new_str[size + 1] = '\0';
		return (new_str);
	}
	else
		return (NULL);
}*/
char	*ft_strnew(size_t size)
{
	char	*str;

	if (size == (size_t)-1)
		return (NULL);
	str = malloc(sizeof(char) * size + 1);
	//str = (char *)malloc(size + 1);
	if (str)
		ft_bzero(str, size + 1);
	else
		return (NULL);
	return (str);
}

