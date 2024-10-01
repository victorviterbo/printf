/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:24:38 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/01 12:14:45 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str);
char	*ft_ftoa_base(double number, char *base);
char	*ft_round(char *str, int precision, char type);
char	*ft_utoa(long number);
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
	return (sign * number);
}

char	*ft_ftoa_base(double number, char *base)
{
	char	*integer;
	char	*decimal;
	long	rounded_num;

	printf("number at first is %f\n", number);
	if (number < 0)
		rounded_num = -(long)(-number);
	else
		rounded_num = (long)(number);
	integer = ft_itoa_base(rounded_num, base);
	if (rounded_num == number)
		return (ft_strjoin(integer, ".000000"));
	printf("integer is %s\n", integer);
	printf("now feeding %f into decimal decipher\n", number - rounded_num);
	decimal = ft_itoa_base_decimal(number - rounded_num, base);
	printf("decimal is %s\n", decimal);
	while (ft_strlen(decimal) < 6)
		decimal = ft_strjoin(decimal, "0");
	printf("on part la dessus ?\n");
	integer = ft_strjoin(ft_strjoin(integer, "."), decimal);
	return (integer);
}

char	*ft_round(char *str, int precision, char type)
{
	if (type == 's')
		return (ft_substr(str, 0, precision));
	else if ((long)ft_strlen(str) < (ft_strchr(str, '.') - str + precision + 1))
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
		return (ft_substr(str, 0, ft_strchr(str, '.') - str + precision + 1));
	}
}

char	*ft_utoa(long number)
{
	if (number < 0)
		return (ft_itoa_base((uint32_t)(number + UINT32_MAX + 1)
			, "0123456789"));
	else
		return (ft_itoa_base((uint32_t)(number), "0123456789"));
}

char	*ft_ctoa(char c)
{
	char	*str;

	str = malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	*str = c;
	*(str + 1) = '\0';
	return (str);
}
