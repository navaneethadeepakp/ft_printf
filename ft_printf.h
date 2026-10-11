/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naperisw <naperisw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:20:39 by naperisw          #+#    #+#             */
/*   Updated: 2025/03/31 11:01:38 by naperisw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_puthexanbr(unsigned int val, int offset);
int	ft_putnbr(int num);
int	ft_putpointer(void *ptr);
int	ft_putstr(char *str);
int	ft_putunsignedint(unsigned int num);

#endif