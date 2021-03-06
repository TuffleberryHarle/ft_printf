/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 13:19:20 by coclayto          #+#    #+#             */
/*   Updated: 2020/06/16 22:14:03 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	float_print2(t_struct *params)
{
	int	i;

	i = 0;
	ft_putstr(params->fbefore);
	params->nprinted_here += params->lenbefore;
	if ((params->hash || params->precision) && !ft_isalpha(params->fbefore[0]))
		params->nprinted_here += write(1, ".", 1);
	if (params->precision)
	{
		while (i++ < params->precision - params->lenafter)
			params->nprinted_here += write(1, "0", 1);
		ft_putstr(params->fafter);
		params->nprinted_here += params->lenafter;
	}
	if (params->width && params->minus)
		while (params->nprinted_here < params->width)
			params->nprinted_here += write(1, " ", 1);
	params->nprinted += params->nprinted_here;
}

void	float_print(t_struct *params)
{
	int len;
	int	indent;

	indent = 0;
	len = params->lenbefore + params->lenafter;
	if ((params->hash || params->precision) && !ft_isalpha(params->fbefore[0]))
		len++;
	if (params->width > len)
		indent = params->width - len;
	if (params->negative || params->plus || params->space)
		indent--;
	if (params->width > len && !params->minus && !params->zero)
		while (indent--)
			params->nprinted_here += write(1, " ", 1);
	if (params->space && !params->negative)
		params->nprinted_here += write(1, " ", 1);
	if (params->negative)
		params->nprinted_here += write(1, "-", 1);
	if (params->plus && !params->negative)
		params->nprinted_here += write(1, "+", 1);
	if (params->width > len && !params->minus && params->zero)
		while (indent--)
			params->nprinted_here += write(1, "0", 1);
	float_print2(params);
}

void	f_increment(t_struct *params)
{
	long double fbefore;

	fbefore = ft_atof(params->fbefore);
	fbefore++;
	params->fbefore = itoa_base_unsigned((uintmax_t)fbefore, 10);
}

int		is_odd(char symb)
{
	return ((symb - '0') % 2);
}

int		is_infnan(t_struct *params, long double num)
{
	params->lenbefore = 3;
	if (num == (1.0 / 0.0) || num == -(1.0 / 0.0))
	{
		if (num == -(1.0 / 0.0))
			params->negative = 1;
		params->fbefore = "inf";
		float_print(params);
		return (1);
	}
	if (!(num == num))
	{
		params->fbefore = "nan";
		params->plus = 0;
		float_print(params);
		return (1);
	}
	return (0);
}
