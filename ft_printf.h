/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seantoni <seantoni@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:59:58 by seantoni          #+#    #+#             */
/*   Updated: 2024/02/12 21:45:44 by seantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include "Libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_puthexa(void *ptr);
int	ft_putnbr(int n);
int	ft_putnbr_unsig(unsigned int n);
int	ft_puthexa_min(int n);
int	ft_puthexa_may(int n);

#endif
