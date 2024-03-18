/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asargsya <asargsya@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:02:45 by asargsya          #+#    #+#             */
/*   Updated: 2024/02/14 15:20:24 by asargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_printf_char(char ch);
int		ft_printf_string(const char *str);
int		ft_printf_int(int number);
int		ft_printf_unsigned(unsigned int number);
int		ft_printf_hex(unsigned int number, int hex_case);
int		ft_printf_pointer(unsigned long long address);

#endif
