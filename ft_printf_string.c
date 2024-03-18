/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asargsya <asargsya@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:02:09 by asargsya          #+#    #+#             */
/*   Updated: 2024/02/14 14:42:47 by asargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_string(const char *str)
{
	int	index;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	index = 0;
	while (*(str + index) != '\0')
	{
		write(1, &str[index], 1);
		index++;
	}
	return (index);
}
