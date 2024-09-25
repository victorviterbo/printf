/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:24:38 by vviterbo          #+#    #+#             */
/*   Updated: 2024/09/25 10:31:52 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str);
char	*ft_ftoa(double number);
char	*ft_round(char *str, int precision, char type);

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
	while ('0' <= *(str + i) && *(str + i) <= '9')
	{
		number = number * 10 + *(str + i) - '0';
		i++;
	}
	return (sign * number);
}

char	*ft_ftoa(double number)
{
	char	*integer;
	char	*decimal;
	int		sign;
	long	rounded_num;

	if (number < 0)
		rounded_num = -(long)(-number);
	else
		rounded_num = (long)(number);
	integer = ft_itoa(rounded_num);
	if (rounded_num == number)
		return (ft_strjoin(integer, ".000000"));
	while ((float)(int)number != number)
	{
		rounded_num *= 10;
		number *= 10;
	}
	decimal = ft_itoa((int)number - rounded_num);
	while (ft_strlen(decimal) < 6)
		decimal = ft_strjoin(decimal, "0");
	return (ft_strjoin(ft_strjoin(integer, "."), decimal));
}

char	*ft_round(char *str, int precision, char type)
{
	if (type == 's')
		return (ft_substr(str, 0, precision));
	else if (ft_strlen(str) < (ft_strchr(str, '.') + precision))
		return (str);
	else if (precision <= 0)
	{
		*(ft_strchr(str, '.') - 1) += (*(ft_strchr(str, '.') + 1) >= 5);
		return (ft_substr(str, 0, ft_strchr(str, '.') - str));
	}
	else
	{
		*(ft_strchr(str, '.') + precision) += (*(ft_strchr(str, '.')
			+ precision + 1) >= 5);
		return (ft_substr(str, 0, ft_strchr(str, '.') - str + precision));
	}
}
