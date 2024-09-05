/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 09:24:56 by vviterbo          #+#    #+#             */
/*   Updated: 2024/08/29 19:13:50 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <float.h>
#include <limits.h>

int	main(void)
{
	int a = 10;
	int b = ++a;
	double d = 100000/DBL_MAX;
	int e = (int)d;
	printf("test: %d\n", INT_MAX);
	printf("test: %d\n", 1/DBL_MAX);
	printf("test: %f\n", d);
	printf("test: %ld\n", e);
}
