/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:55:23 by releanor          #+#    #+#             */
/*   Updated: 2020/03/02 12:57:03 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pos_num_len(int num, int base)
{
	int		num_len;

	num_len = 0;
	num = (num < 0) ? -num : num;
	while (num >= 1)
	{
		num /= base;
		num_len++;
	}
	return (num_len);
}

char	*itoa_base(int num, int base)  //китаец юзает intmax_t, интересно, ёк-макарёк, почему?
{
	char 	*out;
	int 	i;
	int		is_neg;

	i = pos_num_len(num, base);
	is_neg = (num < 0 && base == 10) ? 1 : 0;
	num = (num < 0 && base == 10) ? -num : num;
	out = (char *)malloc(sizeof(char) * (is_neg + i + 1));
	out[i-- + is_neg] = '\0';
	while (i >= 0)
	{
		out[i + is_neg] = (num % base < 10) ? (num % base) + '0' : \
		(num % base + 'a' - 10);
		num /= base;
		i--;
	}
    out[0] = (is_neg == 1) ? '-' : out[0];
	return (out);
}

char	*itoa_base_upp(int num, int base)  //китаец юзает intmax_t, интересно, ёк-макарёк, почему?
{
	char 	*out;
	int 	i;
	int		is_neg;

	i = pos_num_len(num, base);
	is_neg = (num < 0 && base == 10) ? 1 : 0;
	num = (num < 0 && base == 10) ? -num : num;
	out = (char *)malloc(sizeof(char) * (is_neg + i + 1));
	out[i-- + is_neg] = '\0';
	while (i >= 0)
	{
		out[i + is_neg] = (num % base < 10) ? (num % base) + '0' : \
		(num % base + 'A' - 10);
		num /= base;
		i--;
	}
    out[0] = (is_neg == 1) ? '-' : out[0];
	return (out);
}