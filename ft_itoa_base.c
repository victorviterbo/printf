/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:28:28 by vviterbo          #+#    #+#             */
/*   Updated: 2024/08/22 15:44:17 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_itoa_base(int n, char *base);
static size_t	get_log(size_t n, int base_size);
static size_t	get_size(size_t n, int base_size);
static size_t	handle_neg(long *number, char *number_str);

char	*ft_itoa_base(int n, char *base)
{
	char	*number_str;
	size_t	log;
	size_t	i;
	long	number;

	number = n;
	number_str = malloc((get_size(number, ft_strlen(base)) + 2) * sizeof(char));
	if (!number_str)
		return (NULL);
	i = handle_neg(&number, number_str);
	log = get_log(number, ft_strlen(base));
	while (log)
	{
		*(number_str + i) = *(base + number / log);
		number %= log;
		log /= 10;
		i++;
	}
	*(number_str + i) = '\0';
	return (number_str);
}

static size_t	get_log(size_t n, int base_size)
{
	size_t	log;

	log = 1;
	while (n > (base_size * log))
		log *= base_size;
	return (log);
}

static size_t	get_size(size_t n, int base_size)
{
	size_t	size;

	size = 0;
	if (!n)
		return (1);
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n)
	{
		size++;
		n /= base_size;
	}
	return (size);
}

static size_t	handle_neg(long *number, char *number_str)
{
	if (*number < 0)
	{
		*(number_str + 0) = '-';
		*number = -(*number);
		return (1);
	}
	else
		return (0);
}
