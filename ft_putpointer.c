/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naperisw <naperisw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:20:13 by naperisw          #+#    #+#             */
/*   Updated: 2025/03/26 14:15:08 by naperisw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printpointer(unsigned long n)
{
	char			*base;
	unsigned int	count;
	int				res;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		res = ft_printpointer(n / 16);
		count += res;
	}
	res = ft_putchar(base[n % 16]);
	if (res == -1)
		return (res);
	count++;
	return (count);
}

int	ft_putpointer(void *ptr)
{
	unsigned long	pointer;
	int				count;

	pointer = (unsigned long)ptr;
	count = ft_putstr("0x");
	if (count == -1)
		return (count);
	count = count + ft_printpointer(pointer);
	return (count);
}
