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

// static int	ft_handle(char c, va_list list)
// {
// 	int	res;

// 	res = 0;
// 	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
// 		|| c == 'u' || c == 'x' || c == 'X')
// 		res = ft_convertioncases(c, list);
// 	return (res);
// }

// static int	ft_processchar(const char *str, va_list list, int i)
// {
// 	int	res;

// 	res = 0;
// 	res = ft_handle(str[i], list);
// 	return (res);
// }

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

#include <stdio.h> 
int main()
{
    char c = 'A';
    char *str = "Hello, world!";
    int num = 12;
    unsigned int u_num = 4294967295;
    int hex_num = 255;
    void *ptr = &num;

    printf("\n---Character Test---\n");
    printf("   printf  c : %c\n", c);
    ft_printf("ft_printf  c : %c\n", c);

    printf("\n--- String Test ---\n");
    printf("   printf  s : %s\n", str);
    ft_printf("ft_printf  s : %s\n", str);

	printf("\n--- Pointer Test ---\n");
    printf("   printf  p : %p\n", ptr);
    ft_printf("ft_printf  p : %p\n", ptr);
	
    printf("\n--- Integer Test ---\n");
    printf("   printf d: %d\n", num);
    ft_printf("ft_printf d : %d\n", num);

	printf("\n--- Integer Test ---\n");
    printf("   printf  i : %i\n", num);
    ft_printf("ft_printf  i : %i\n", num);

    printf("\n--- Unsigned Integer Test ---\n");
    printf("   printf  u : %u\n", u_num);
    ft_printf("ft_printf  u : %u\n", u_num);

    printf("\n--- Hexadecimal Test (lowercase) ---\n");
    printf("   printf  x : %x\n", hex_num);
    ft_printf("ft_printf  x : %x\n", hex_num);

    printf("\n--- Hexadecimal Test (uppercase) ---\n");
    printf("   printf  X : %X\n", hex_num);
    ft_printf("ft_printf  X : %X\n", hex_num);

    printf("\n--- Percent Sign Test ---\n");
    printf("   printf  %% : %%\n");
    ft_printf("ft_printf  %% : %%\n");   

    return 0;
} 