/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:28:28 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/01 14:40:14 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_itoa_base(long n, char *base);
char			*ft_itoa_base_decimal(double n, char *base);
static size_t	get_log(size_t n, float base_size);
static size_t	get_size(size_t n, float base_size);
static size_t	handle_neg(long *number, char *number_str);

char	*ft_itoa_base(long n, char *base)
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
		log /= ft_strlen(base);
		i++;
	}
	*(number_str + i) = '\0';
	return (number_str);
}

char	*ft_itoa_base_decimal(double number, char *base)
{
	char	*number_str;
	double	log;
	size_t	i;

	i = 0;
	if (number < 0)
		number *= -1;
	number_str = malloc((get_size(number, 1 / ft_strlen(base)) + 2)
			* sizeof(char));
	if (!number_str)
		return (NULL);
	log = 1 / (double)ft_strlen(base);
	while (number > 0)
	{
		*(number_str + i) = *(base + (int)(number / log));
		number = number - (log * (int)(number / log));
		log /= ft_strlen(base);
		i++;
	}
	*(number_str + i) = '\0';
	return (number_str);
}

static size_t	get_log(size_t n, float base_size)
{
	size_t	log;

	log = 1;
	if (base_size > 1)
	{
		while (n / (base_size * log) > 1)
			log *= base_size;
	}
	else
	{
		while (n / (base_size * log) < 1)
			log *= base_size;
	}
	return (log);
}

static size_t	get_size(size_t n, float base_size)
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
	while (n >= (1 / base_size))
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
		*(number_str) = '-';
		*number = -(*number);
		return (1);
	}
	else
		return (0);
}
