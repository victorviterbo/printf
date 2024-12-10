/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:28:28 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/10 13:05:39 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_itoa_base(long long n, char *base);
static size_t	get_log(size_t n, size_t base_size);
static size_t	get_size(long long n, int base_size);
static size_t	handle_neg(long long *number, char *number_str);

char	*ft_itoa_base(long long n, char *base)
{
	char		*number_str;
	size_t		log;
	size_t		i;
	long long	number;

	number = n;
	number_str = ft_calloc((get_size(number, ft_strlen(base)) + 2),
			sizeof(char));
	if (!number_str)
		return (NULL);
	i = handle_neg(&number, number_str);
	log = get_log(number, ft_strlen(base));
	while (log)
	{
		*(number_str + i) = *(base + number / log);
		number %= log;
		log /= ft_strlen(base);
		i++;
	}
	*(number_str + i) = '\0';
	return (number_str);
}

size_t	get_log(size_t n, size_t base_size)
{
	unsigned long long	log;

	log = 1;
	while (n >= base_size)
	{
		log *= base_size;
		n /= base_size;
	}
	return (log);
}

size_t	get_size(long long n, int base_size)
{
	size_t	size;

	size = (n < 0);
	if (n < 0)
		n *= -1;
	if (base_size <= 0)
		return (0);
	if (!n)
		return (1);
	while (n > 0)
	{
		size++;
		n /= base_size;
	}
	return (size);
}

size_t	handle_neg(long long *number, char *number_str)
{
	if (*number < 0)
	{
		*(number_str) = '-';
		*number = -(*number);
		return (1);
	}
	else
		return (0);
}
