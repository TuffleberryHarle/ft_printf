/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 23:04:46 by releanor          #+#    #+#             */
/*   Updated: 2020/03/03 08:23:36 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_print(t_struct *params, char c, int indent)
{
	if (params->width > 1 && !params->minus)
	{
		indent = params->width - 1;
		{
			while (indent--)
				params->nprinted_here += (params->zero && !params->precision) \
				? write(1, "0", 1) : \
				write(1, " ", 1);
		}
	}
	if (c == '\0')
		params->nprinted_here += write(1, "\0", 1);
	else
		params->nprinted_here += write(1, &c, 1);
	if (params->width && params->minus)
		while (params->nprinted_here < params->width)
			params->nprinted_here += write(1, " ", 1);
	params->nprinted += params->nprinted_here;
}

void	type_char(va_list args, t_struct *params)
{
	unsigned char	c;

	c = (unsigned char)va_arg(args, int);
	// if (params->precision || params->plus \
	// || params->hash || params->space)
	// 	exit(1);
	char_print(params, c, 0);
	bzerostruct(params, 0);
}