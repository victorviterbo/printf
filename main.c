/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 09:24:56 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/14 19:54:25 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <float.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	void	*str;

	str = malloc(sizeof(void));
	/*printf("\001\002\007\v\010\f\r\n");
	printf("><><><\n");
	ft_printf("\001\002\007\v\010\f\r\n");*/
	printf("----------------------\n");
	printf("test1 %0-19.2d\n", 456);
	printf("><><><\n");
	printf("TF DID U SAY ?\n");
	ft_printf("test1 %0-19.2d\n", 456);
	printf("----------------------\n");
	/*
	printf("test2 %0-19.2u\n", -12);
	printf("><><><\n");
	ft_printf("test2 %0-19.2u\n", -12);
	printf("----------------------\n");
	printf("test3 >%p<\n", str); // handle the 0x at the beggining
	printf("><><><\n");
	ft_printf("test3 >%p<\n", str); // handle the 0x at the beggining
	printf("test4 ok %x\n", 456);
	ft_printf("test4 %x\n", 456);
	printf("test5 ok %019.2X\n", 456);
	ft_printf("test5 %019.2X\n", 456);
	printf("0 test %c, %s, %p, %05.2d, %05.3i, %05u, %05x, %05X\n", 'a', "bla", str, 123, 123, 123, 123, 123);
	ft_printf("width tests %+d\n", -182.123);*/
}
