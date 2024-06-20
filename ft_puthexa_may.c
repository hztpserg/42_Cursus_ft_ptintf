/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seantoni <seantoni@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:35:25 by seantoni          #+#    #+#             */
/*   Updated: 2024/02/12 21:43:54 by seantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexa_may_long(char *hexa_digits, unsigned long long n, int len)
{
	unsigned long long	base;

	base = ft_strlen(hexa_digits);
	if (n >= base)
	{
		len = hexa_may_long(hexa_digits, n / base, len);
		if (len == -1)
			return (-1);
		if (write(1, &hexa_digits[n % base], 1) == -1)
			return (-1);
		len++;
	}
	else if (n < base)
	{
		if (write(1, &hexa_digits[n], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}

static int	hexa_may_int(char *hexa_digits, unsigned int n, int len)
{
	unsigned int	base;

	base = ft_strlen(hexa_digits);
	if (n >= base)
	{
		len = hexa_may_int(hexa_digits, n / base, len);
		if (len == -1)
			return (-1);
		if (write(1, &hexa_digits[n % base], 1) == -1)
			return (-1);
		len++;
	}
	else if (n < base)
	{
		if (write(1, &hexa_digits[n], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_puthexa_may(int n)
{
	int		len;
	char	*hexa_digits;

	len = 0;
	hexa_digits = "0123456789ABCDEF";
	if (n >= 0)
		len = hexa_may_long(hexa_digits, n, len);
	else if (n < 0)
		len = hexa_may_int(hexa_digits, n, len);
	return (len);
}
