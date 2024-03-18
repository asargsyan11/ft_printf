/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asargsya <asargsya@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:46:03 by asargsya          #+#    #+#             */
/*   Updated: 2024/02/15 10:26:35 by asargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_hex(unsigned int n)
{
	int	size;

	if (n <= 0)
		size = 1;
	else
		size = 0;
	while (n)
	{
		size++;
		n /= 16;
	}
	return (size);
}

int	ft_printf_hex(unsigned int number, int hex_case)
{
	char			*base_16;
	int				size;

	size = size_hex(number);
	if (hex_case == 87)
		base_16 = "0123456789abcdef";
	else if (hex_case == 55)
		base_16 = "0123456789ABCDEF";
	if (number < 16)
	{
		ft_printf_char(base_16[number]);
	}
	else
	{
		ft_printf_hex(number / 16, hex_case);
		ft_printf_hex(number % 16, hex_case);
	}
	return (size);
}
