/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 09:24:56 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/01 12:19:35 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <float.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	//printf("test0 %010i\n", 123);
	//ft_printf("test1 %i_ _test2 %i\n", 123, 456);
	ft_printf("test1 %0-19.2d\n", 456.789);
	ft_printf("test2 %0-19.2u\n", -12);
}
