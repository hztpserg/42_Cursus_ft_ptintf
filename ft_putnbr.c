/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seantoni <seantoni@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:14:04 by seantoni          #+#    #+#             */
/*   Updated: 2024/02/08 00:41:41 by seantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	n_write(char *c, int n)
{
	if (write(1, c, n) != n)
		return (-1);
	return (n);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == INT_MIN)
		return (n_write("-2147483648", 11));
	if (n < 0 && ++len)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n = -n;
	}
	if (n >= 10)
	{
		len += ft_putnbr(n / 10);
		if (len == -1)
			return (-1);
		n = n % 10;
	}
	if (n < 10)
	{
		if (ft_putchar((n + '0')) == -1)
			return (-1);
		len++;
	}
	return (len);
}
