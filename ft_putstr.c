/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seantoni <seantoni@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:22:26 by seantoni          #+#    #+#             */
/*   Updated: 2024/02/06 14:34:12 by seantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	size_t	i;

	if (!str)
	{
		if (write(1, "(null)", 6) != 6)
			return (-1);
		else
			return (6);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (write(1, &str[i], 1) != 1)
			return (-1);
		i++;
	}
	return (i);
}
