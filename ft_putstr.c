/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naperisw <naperisw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:20:25 by naperisw          #+#    #+#             */
/*   Updated: 2025/03/26 12:47:24 by naperisw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	unsigned int	count;

	count = 0;
	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	while (str[count])
		count++;
	return (write(1, str, count));
}
