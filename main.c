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

#include <stdio.h>
#include "ft_printf.h"

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