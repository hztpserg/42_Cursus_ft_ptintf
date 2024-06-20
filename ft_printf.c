/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seantoni <seantoni@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 01:04:18 by seantoni          #+#    #+#             */
/*   Updated: 2024/02/11 00:55:36 by seantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	espec_args(char espec, va_list args)
{
	if (espec == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (espec == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (espec == 'p')
		return (ft_puthexa(va_arg(args, void *)));
	if (espec == 'd' || espec == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (espec == 'u')
		return (ft_putnbr_unsig(va_arg(args, unsigned int)));
	if (espec == 'x')
		return (ft_puthexa_min(va_arg(args, int)));
	if (espec == 'X')
		return (ft_puthexa_may(va_arg(args, int)));
	return (0);
}

static int	porcen_args(char c, va_list args)
{
	int	len;

	len = 1;
	if (c != '%')
		len = espec_args(c, args);
	else
	{
		if (write(1, &c, 1) == -1)
			return (-1);
	}
	return (len);
}

static int	iter_args(const char *format, va_list args, int count)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len = porcen_args(format[i + 1], args);
			if (len == -1)
				return (-1);
			count = count + len;
			i++;
		}
		else
		{
			if (write(1, &format[i], 1) != 1)
				return (-1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	count = iter_args(format, args, count);
	va_end(args);
	return (count);
}
