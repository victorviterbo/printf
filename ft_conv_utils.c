/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:24:38 by vviterbo          #+#    #+#             */
/*   Updated: 2024/09/26 12:51:41 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str);
char	*ft_ftoa_base(double number, char *base);
char	*ft_round(char *str, int precision, char type);
char	*ft_ctoa(char c);


int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		number;

	i = 0;
	sign = 1;
	number = 0;
	printf("blabla\n");
	while ((9 <= *(str + i) && *(str + i) <= 13) || *(str + i) == 32)
		i++;
	if (*str == '-')
	{
		sign *= -1;
		i++;
	}
	else if (*str == '+')
		i++;
	printf("blibli\n");
	while (*(str + i) && '0' <= *(str + i) && *(str + i) <= '9')
	{
		number = number * 10 + *(str + i) - '0';
		i++;
	}
	printf("bloublou %d\n", sign * number);
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
	printf("HELLO1\n");
	while (ft_strlen(decimal) < 6)
		decimal = ft_strjoin(decimal, "0");
	printf("on part la dessus ?\n");
	integer = ft_strjoin(integer, ".");//ft_strjoin(ft_strjoin(integer, "."), decimal);
	printf("strjoin on decimal : %s\n", integer);
	integer = ft_strjoin(integer, decimal);
	printf("strjoin on decimal : %s\n", integer);
	return (integer);
}

char	*ft_round(char *str, int precision, char type)
{
	if (type == 's')
		return (ft_substr(str, 0, precision));
	else if (ft_strlen(str) < (size_t)(ft_strchr(str, '.') - str + precision + 1))
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
