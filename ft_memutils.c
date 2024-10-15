/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:56:16 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/15 16:31:01 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int						i;

	if (!dst || ! src || n < 0)
		return (NULL);
	if (src < dst && dst < src + n)
	{
		i = n - 1;
		while (i + 1)
		{
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while ((size_t)i < n)
		{
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
			i++;
		}	
	}
	return (dst);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*bptr;
	size_t			i;

	i = 0;
	if (!count || !size)
		return (malloc(0));
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	bptr = (unsigned char *)ptr;
	while (i < (count * size))
	{
		*(bptr + i) = '\0';
		i++;
	}
	return (ptr);
}
