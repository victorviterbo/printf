/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:24:38 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/10 13:06:10 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_utoa_base(unsigned long number, char *base);
static size_t	get_usize(unsigned long n, int base_size);

char	*ft_utoa_base(unsigned long number, char *base)
{
	char				*number_str;
	size_t				log;
	size_t				i;

	i = 0;
	number_str = ft_calloc((get_usize(number, ft_strlen(base)) + 2),
			sizeof(char));
	if (!number_str)
		return (NULL);
	log = ft_log_base(number, ft_strlen(base));
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

static size_t	get_usize(unsigned long n, int base_size)
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

char	*ft_ctoa(char c)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (NULL);
	*str = c % 256;
	*(str + 1) = '\0';
	return (str);
}
