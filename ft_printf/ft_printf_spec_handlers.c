/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specificators.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:41:33 by mchau             #+#    #+#             */
/*   Updated: 2021/01/15 20:00:11 by mchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_nchr(char c, int n)
{
	while (n > 0)
	{
		write(1, &c, 1);
		n--;
	}
}

int	c_handler(t_params *t, va_list arg)
{
	char	c;
	int		result_count;

	c = (char)va_arg(arg, int);
	if (t->width <= 1)
	{
		write(1, &c, 1);
		return (1);
	}
	result_count = t->width - 1;
	if (!t->minus)
		print_nchr(' ', result_count);
	write(1, &c, 1);
	if(t->minus)
		print_nchr(' ', result_count);
	return (t->width);
}

int	s_handler(t_params *t, va_list arg)
{
	char	*s;
	int		result_count;
	int		i;

	i = 0;
	result_count = 0;
	s = (char *)va_arg(arg, void *);
	while (s[i] != 0)
		i++;
	if (t->dot && t->precision >= 0 && i >= t->precision)
		i = t->precision;
	if (t->width > i)
		result_count = t->width - i;
	if (!t->minus)
		print_nchr(' ', result_count);
	write(1, s, i);
	if (t->minus)
		print_nchr(' ', result_count);
	return (result_count + i);
}

int	percent_handler(t_params *t, va_list arg)
{
;
}
/*

s_handler
p_handler
d_handler
u_handlex
x_handler
percent_handler
*/