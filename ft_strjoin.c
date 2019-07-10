/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 03:26:40 by rpizpot           #+#    #+#             */
/*   Updated: 2019/04/10 21:23:50 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;

	if (s1 && s2)
	{
		i = 0;
		new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!new_str)
			return (NULL);
		new_str = ft_strcpy(new_str, s1);
		while (i < ft_strlen(s2))
		{
			new_str[ft_strlen(s1) + i] = s2[i];
			i++;
		}
		new_str[ft_strlen(s1) + i] = '\0';
		return (new_str);
	}
	return (NULL);
}
