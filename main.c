/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 09:24:56 by vviterbo          #+#    #+#             */
/*   Updated: 2024/09/26 11:19:51 by vviterbo         ###   ########.fr       */
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
	ft_printf("test3 %19.2d", 456.789);
}
