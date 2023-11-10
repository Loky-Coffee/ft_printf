/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:39:41 by aalatzas          #+#    #+#             */
/*   Updated: 2023/11/10 06:08:29 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	if (s[i] != '\0')
	{
		while (s[i] != '\0')
			i++;
		return (i);
	}
	return (0);
}

int	ft_putchar_fd(int c, int fd, t_counter *data)
{
	int	j;

	j = 0;
	j = write(fd, &c, 1);
	if (j < 0)
		return (-1);
	data->counter += j;
	return (j);
}

int	ft_putstr_fd(char *s, int fd, t_counter *data)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s);
	if (s == NULL)
	{
		j = write(1, "(null)", 6);
		if (j < 0)
			return (-1);
		data->counter += j;
	}
	while (s != NULL && s[i] != '\0')
	{
		i++;
		data->counter++;
	}
	j = write(fd, s, i);
	return (j);
}

int	ft_putptr(unsigned long n, int fd, t_counter *data, char *basestr)
{
	int	j;

	if (n >= ft_strlen(basestr))
	{
		j = ft_putptr(n / ft_strlen(basestr), fd, data, basestr);
		if (j == -1)
			return (-1);
	}
	j = ft_putchar_fd(basestr[n % ft_strlen(basestr)], fd, data);
	return (j + 2);
}
