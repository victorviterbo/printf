/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:28:17 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/01 13:44:54 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*bdst;
	unsigned char	*bsrc;

	i = 0;
	bdst = (unsigned char *)dst;
	bsrc = (unsigned char *)src;
	printf("n = %lu\n", n);
	while (i < n)
	{
		*(bdst + i) = *(bsrc + i);
		write(1, bsrc + i, 1);
		write(1, "ok ?", 4);
		i++;
	}
	return (dst);
}
