/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:55:56 by mchau             #+#    #+#             */
/*   Updated: 2021/01/22 11:28:33 by mchau            ###   ########.fr       */
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
