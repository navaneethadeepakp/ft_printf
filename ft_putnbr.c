/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naperisw <naperisw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:20:08 by naperisw          #+#    #+#             */
/*   Updated: 2025/03/26 15:19:14 by naperisw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_recurssive(long n)
{
	unsigned int	count;
	int				res;

	count = 0;
	if (n >= 10)
	{
		res = ft_putnbr_recurssive(n / 10);
		if (res == -1)
			return (-1);
		count += res;
	}
	res = ft_putchar((n % 10) + '0');
	if (res == -1)
		return (-1);
	return (count + 1);
}

int	ft_putnbr_negative(long *n)
{
	unsigned int	count;
	int				res;

	count = 0;
	if (*n == -2147483648)
	{
		res = write(1, "-2", 2);
		if (res == -1)
			return (-1);
		*n = 147483648;
		count += 2;
	}
	if (*n < 0)
	{
		*n = -(*n);
		res = ft_putchar('-');
		if (res == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_putnbr(int num)
{
	unsigned int	count;
	int				res;
	long			n;

	n = num;
	count = 0;
	res = ft_putnbr_negative(&n);
	if (res == -1)
		return (-1);
	count += res;
	res = ft_putnbr_recurssive(n);
	if (res == -1)
		return (-1);
	count += res;
	return (count);
}
