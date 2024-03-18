/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asargsya <asargsya@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:20:52 by asargsya          #+#    #+#             */
/*   Updated: 2024/03/18 11:42:38 by asargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_char_exists(const char *str, char c)
{
	int	index;

	if (!str)
		return (0);
	index = 0;
	while (*(str + index) != '\0')
	{
		if (*(str + index) == c)
			return (1);
		index++;
	}
	return (0);
}

static int	format_check(char *format, va_list args)
{
	int	len;

	len = 0;
	if (*format == 'c')
		len += ft_printf_char(va_arg(args, int));
	else if (*format == 'i' || *format == 'd')
		len += ft_printf_int(va_arg(args, int));
	else if (*format == 'u')
		len += ft_printf_unsigned(va_arg(args, unsigned int));
	else if (*format == 's')
		len += ft_printf_string(va_arg(args, const char *));
	else if (*format == 'p')
		len += ft_printf_pointer(va_arg(args, unsigned long long));
	else if (*format == 'x')
		len += ft_printf_hex(va_arg(args, unsigned int), 87);
	else if (*format == 'X')
		len += ft_printf_hex(va_arg(args, unsigned int), 55);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	int				index;

	va_start(args, format);
	index = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (ft_char_exists("cspdiuxX", *format))
				index += format_check((char *)format, args);
			else if (*format == '%')
				index += ft_printf_char('%');
		}
		else
			index += ft_printf_char(*format);
		format++;
	}
	va_end(args);
	return (index);
}
