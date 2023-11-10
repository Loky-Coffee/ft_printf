/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 01:55:31 by aalatzas          #+#    #+#             */
/*   Updated: 2023/11/10 03:43:13 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_counter
{
	int	counter;
}		t_counter;

int		ft_printf(const char *input, ...);
int		ft_putnbr_fd(long int n, int fd, t_counter *data, char *basestr);
size_t	ft_strlen(const char *s);
int		ft_putchar_fd(int c, int fd, t_counter *data);
int		ft_putstr_fd(char *s, int fd, t_counter *data);
int		ft_putptr(unsigned long n, int fd, t_counter *data, char *basestr);

#endif
