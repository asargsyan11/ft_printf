/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asargsya <asargsya@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:16:56 by asargsya          #+#    #+#             */
/*   Updated: 2024/02/14 14:40:32 by asargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(int n)
{
	int	res;
	int	num;

	num = n;
	res = 0;
	if (num <= 0)
	{
		res++;
	}
	num *= -1;
	while (num)
	{
		num /= 10;
		res++;
	}
	return (res);
}

static void	ft_putstr(const char *str)
{
	int	index;

	index = 0;
	if (!str)
		return ;
	while (*(str + index) != '\0')
	{
		write(1, &str[index], 1);
		index++;
	}
}

static int	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;

	len = get_len(n);
	num = n;
	str = (char *)malloc(sizeof(char) * (get_len(n) + 1));
	if (!str)
		return (0);
	*(str + len) = '\0';
	if (num == 0)
		str[0] = '0';
	else if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	ft_putstr(str);
	free(str);
	return (0);
}

int	ft_printf_int(int number)
{
	int	num_len;

	num_len = get_len(number);
	ft_itoa(number);
	return (num_len);
}
