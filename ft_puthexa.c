/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seantoni <seantoni@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:27:53 by seantoni          #+#    #+#             */
/*   Updated: 2024/02/07 00:39:27 by seantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	puthexa_recursive(char *hexa_digits, unsigned long long p, int len)
{
	unsigned long long	n;

	n = ft_strlen(hexa_digits);
	if (p >= n)
	{
		len = puthexa_recursive(hexa_digits, p / n, len);
		if (len == -1)
			return (-1);
		if (write(1, &hexa_digits[p % n], 1) == -1)
			return (-1);
		len++;
	}
	else if (p < n)
	{
		if (write(1, &hexa_digits[p], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_puthexa(void *ptr)
{
	int					len;
	char				*hexa_digits;
	unsigned long long	p;

	if (write(1, "0x", 2) != 2)
		return (-1);
	len = 0;
	hexa_digits = "0123456789abcdef";
	p = (unsigned long long)ptr;
	len = puthexa_recursive(hexa_digits, p, len);
	if (len == -1)
		return (-1);
	len += 2;
	return (len);
}
