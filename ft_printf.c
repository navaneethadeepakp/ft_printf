/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naperisw <naperisw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:19:45 by naperisw          #+#    #+#             */
/*   Updated: 2025/03/31 15:38:42 by naperisw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convertioncases(const char c, va_list list)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(list, int));
	else if (c == 's')
		count = ft_putstr(va_arg(list, char *));
	else if (c == 'p')
		count = ft_putpointer(va_arg(list, void *));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(list, int));
	else if (c == 'u')
		count = ft_putunsignedint(va_arg(list, unsigned int));
	else if (c == 'x')
		count = ft_puthexanbr(va_arg(list, unsigned int), 0);
	else if (c == 'X')
		count = ft_puthexanbr(va_arg(list, unsigned int), 1);
	else if (c == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	unsigned int	count;
	va_list			list;
	int				i;
	int				res;

	i = 0;
	count = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			res = ft_convertioncases(str[i], list);
		}
		else
			res = ft_putchar(str[i]);
		if (res == -1)
			return (-1);
		count += res;
		i++;
	}
	va_end(list);
	return (count);
}
