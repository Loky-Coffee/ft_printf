/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 00:28:44 by aalatzas          #+#    #+#             */
/*   Updated: 2023/11/10 07:38:03 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putnbr_fd(long int n, int fd, t_counter *data, char *basestr)
{
	int	base;
	int	j;

	j = 0;
	base = ft_strlen(basestr);
	if (n < 0)
	{
		j = ft_putstr_fd("-", fd, data);
		if (j != 1)
			return (-1);
		n = n * -1;
	}
	if (n >= base)
	{
		j = ft_putnbr_fd(n / base, fd, data, basestr);
		if (j < 0)
			return (-1);
		if (ft_putchar_fd(basestr[n % base], fd, data) != 1)
			return (-1);
	}
	else
		if (ft_putchar_fd(basestr[n], fd, data) != 1)
			return (-1);
	return (1);
}

int	check_args(char template, va_list args, t_counter *data)
{
	if (template == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1, data));
	else if (template == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1, data));
	else if (template == 'p')
		return (ft_putptr((long)va_arg(args, void *), \
		1, data, "0123456789abcdef"));
	else if (template == 'd')
		return (ft_putnbr_fd(va_arg(args, int), 1, data, "0123456789"));
	else if (template == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1, data, "0123456789"));
	else if (template == 'u')
		return (ft_putnbr_fd(va_arg(args, unsigned int), \
		1, data, "0123456789"));
	else if (template == 'x')
		return (ft_putnbr_fd((unsigned int)va_arg(args, int), 1, data, \
		"0123456789abcdef"));
	else if (template == 'X')
		return (ft_putnbr_fd((unsigned int)va_arg(args, int), 1, data, \
		"0123456789ABCDEF"));
	else if (template == '%')
		return (ft_putchar_fd('%', 1, data));
	return (1);
}

int	ft_printf(const char *input, ...)
{
	t_counter	data;
	va_list		args;

	va_start(args, input);
	data.counter = 0;
	while (*input != '\0')
	{
		if (*input == '%')
		{
			if (*(++input) == 'p')
				if (ft_putstr_fd("0x", 1, &data) != 2)
					return (-1);
			if (check_args(*input++, args, &data) == -1)
				return (-1);
		}
		else
		{
			if (write(1, input, 1) != 1)
				return (-1);
			data.counter++;
			input++;
		}
	}
	va_end(args);
	return (data.counter);
}
