/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seantoni <seantoni@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:56:21 by seantoni          #+#    #+#             */
/*   Updated: 2024/02/10 19:58:26 by seantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsig(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putnbr_unsig(n / 10);
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
