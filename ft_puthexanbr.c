/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexanbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naperisw <naperisw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:20:02 by naperisw          #+#    #+#             */
/*   Updated: 2025/03/31 11:15:58 by naperisw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexanbr(unsigned int n, int decider)
{
	char	*base;
	int		count;

	if (decider == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (n == 0)
	{
		if (ft_putchar ('0') == -1)
			return (-1);
		return (1);
	}
	if (n >= 16)
	{
		count += ft_puthexanbr(n / 16, decider);
		if (count == -1)
			return (-1);
	}
	if (ft_putchar(base[n % 16]) == -1)
		return (-1);
	count++;
	return (count);
}
