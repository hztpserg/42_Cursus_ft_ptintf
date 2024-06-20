/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_min.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seantoni <seantoni@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 23:56:58 by seantoni          #+#    #+#             */
/*   Updated: 2024/02/11 00:07:37 by seantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexa_min_long(char *hexa_digits, unsigned long long num, int len)
{
	unsigned long long	base;

	base = ft_strlen(hexa_digits);
	if (num >= base)
	{
		len = hexa_min_long(hexa_digits, num / base, len);
		if (len == -1)
			return (-1);
		if (write(1, &hexa_digits[num % base], 1) == -1)
			return (-1);
		len++;
	}
	else if (num < base)
	{
		if (write(1, &hexa_digits[num], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}

static int	hexa_min_int(char *hexa_digits, unsigned int num, int len)
{
	unsigned int	base;

	base = ft_strlen(hexa_digits);
	if (num >= base)
	{
		len = hexa_min_int(hexa_digits, num / base, len);
		if (len == -1)
			return (-1);
		if (write(1, &hexa_digits[num % base], 1) == -1)
			return (-1);
		len++;
	}
	else if (num < base)
	{
		if (write(1, &hexa_digits[num], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_puthexa_min(int n)
{
	int		len;
	char	*hexa_digits;

	len = 0;
	hexa_digits = "0123456789abcdef";
	if (n >= 0)
		len = hexa_min_long(hexa_digits, n, len);
	else if (n < 0)
		len = hexa_min_int(hexa_digits, n, len);
	return (len);
}
