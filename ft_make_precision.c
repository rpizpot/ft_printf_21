/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 22:21:30 by hlarson           #+#    #+#             */
/*   Updated: 2019/07/10 22:21:33 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_make_precision(char *c, int i)
{
    int     j;

    j = get_after_dot_float(c);
    if (i == j)
        c = ft_strjoin(c, ft_strdup("0"));
    if (i > j)
        c = ft_strjoin(c, ft_strnew_zero(i - j + 1));
    if (i < j)
        c = ft_right_precision(c, i);
    return (c);
}