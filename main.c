/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 09:24:56 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/15 20:17:07 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <float.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	void	*str;

	str = malloc(sizeof(void));
	printf("\n----------------------\n"); //OK !
	printf("%s", (char *)NULL);
	printf("\n><><><\n");
	ft_printf("%s", (char *)NULL);
	printf("\n----------------------\n"); //OK !
	printf("%p", (void *)-14523);
	printf("\n><><><\n");
	ft_printf("%p", (void *)-14523);
	printf("\n----------------------\n"); //OK !
	printf(" %c %c %c ", '0', 0, '1');
	printf("\n><><><\n");
	ft_printf(" %c %c %c ", '0', 0, '1');
	printf("\n----------------------\n"); //OK !
	printf("\ndiff between return values ar %i, %i\n", printf(" %c %c %c ", '0', 0, '1'), ft_printf(" %c %c %c ", '0', 0, '1'));
	printf("\n----------------------\n"); //OK !
	printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("\n><><><\n");
	ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("\n----------------------\n"); //OK !
	printf("\001\002\007\v\010\f\r\n");
	printf("><><><\n");
	ft_printf("\001\002\007\v\010\f\r\n");
	printf("----------------------\n"); //OK !
	printf("%%%c", 'x');
	printf("\n><><><\n");
	ft_printf("%%%c", 'x');
	printf("\n----------------------\n"); //OK !
	printf("> %%<");
	printf("\n><><><\n");
	ft_printf("> %%<");
	printf("\n----------------------\n"); //OK !
	printf("test1 %19.2d\n", 456);
	printf("><><><\n");
	ft_printf("test1 %19.2d\n", 456);
	printf("----------------------\n"); //OK !
	printf("test2 %-19.2u\n", -12);
	printf("><><><\n");
	ft_printf("test2 %-19.2u\n", -12);
	printf("----------------------\n"); //OK !
	printf("test3 >%p<\n", str);
	printf("><><><\n");
	ft_printf("test3 >%p<\n", str);
	printf("----------------------\n"); //OK !
	printf("test4 %x\n", 456);
	printf("><><><\n");
	ft_printf("test4 %x\n", 456);
	printf("----------------------\n"); //OK !
	printf("test5 %019X\n", 456);
	printf("><><><\n");
	ft_printf("test5 %019X\n", 456);
	printf("----------------------\n");
	printf("test1 %019.2d\n", 456);
	printf("><><><\n");
	ft_printf("test1 %019.2d\n", 456);
	printf("----------------------\n");
	printf("test1 %019i\n", 456);
	printf("><><><\n");
	ft_printf("test1 %019i\n", 456);/*
	printf("0 test %c, %s, %p, %05.2d, %05.3i, %05u, %05x, %05X\n", 'a', "bla", str, 123, 123, 123, 123, 123);
	ft_printf("width tests %+d\n", -182.123);*/
}
