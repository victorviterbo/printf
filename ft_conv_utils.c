/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:24:38 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/15 20:18:55 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str);
char	*ft_utoa_base(long number, char *base);
size_t	get_usize(unsigned long n, int base_size);
char	*ft_ctoa(char c);

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		number;

	i = 0;
	sign = 1;
	number = 0;
	while ((9 <= *(str + i) && *(str + i) <= 13) || *(str + i) == 32)
		i++;
	if (*str == '-')
	{
		sign *= -1;
		i++;
	}
	else if (*str == '+')
		i++;
	while (*(str + i) && '0' <= *(str + i) && *(str + i) <= '9')
	{
		number = number * 10 + *(str + i) - '0';
		i++;
	}
	free((void *)str);
	return (sign * number);
}

char	*ft_utoa_base(long n, char *base)
{
	char				*number_str;
	size_t				log;
	size_t				i;
	unsigned long		number;

	i = 0;
	if (n < 0)
	{
		number = UINT64_MAX;
		number = number + n + 1;
	}
	else
		number = n;
	number_str = ft_calloc((get_usize(number, ft_strlen(base)) + 2)
		, sizeof(char));
	if (!number_str)
		return (NULL);
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

size_t	get_usize(unsigned long n, int base_size)
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
