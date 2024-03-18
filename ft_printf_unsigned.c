/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asargsya <asargsya@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:55:33 by asargsya          #+#    #+#             */
/*   Updated: 2024/02/15 10:26:13 by asargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(unsigned int number)
{
	if (number >= 10)
		ft_printf_unsigned(number / 10);
	if (number <= 9)
	{
		ft_putchar(number + 48);
		return ;
	}
	ft_putchar((number % 10) + 48);
}

int	ft_printf_unsigned(unsigned int number)
{
	unsigned int	len;

	ft_putnbr(number);
	len = 1;
	while (number >= 10)
	{
		number /= 10;
		len++;
	}
	return (len);
}
