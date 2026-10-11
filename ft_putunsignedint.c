/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignedint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naperisw <naperisw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:20:31 by naperisw          #+#    #+#             */
/*   Updated: 2025/03/26 14:19:26 by naperisw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsignedint(unsigned int num)
{
	unsigned int	count;
	int				res;

	count = 0;
	if (num >= 10)
	{
		res = ft_putunsignedint(num / 10);
		if (res == -1)
			return (-1);
		count += res;
	}
	res = ft_putchar((num % 10) + '0');
	if (res == -1)
		return (-1);
	count++;
	return (count);
}
