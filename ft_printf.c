/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:01:06 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/14 16:43:01 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...);
void	print_format(char *str, va_list argl);
char	*get_radix(char type, va_list argl);
char	*set_width(char *formated, char *str, int *width);
char	*set_precision(char *formated, char *str, int *precision);

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	j;
	va_list	argl;

	i = 0;
	va_start(argl, str);
	while (*(str + i))
	{
		if (*(str + i) != '%' || (*(str + i) == '%' && *(str + i + 1) == '%'))
		{
			if (*(str + i) == '%')
				i++;
			write(1, (str + i), 1);
			i++;
			continue ;
		}
		j = ++i;
		while (*(str + j - 1) && !ft_strchr("cspdiuxX", *(str + j - 1)))
			j++;
		print_format(ft_substr(str, i, j - i), argl);
		i = j;
	}
	va_end(argl);
	return (1);
}

void	print_format(char *str, va_list argl)
{
	char	*formated;
	int		*width;
	int		*precision;

	width = NULL;
	precision = NULL;
	if (ft_strchr(str, '*'))
	{
		if (!ft_strchr(str, '.') || (ft_strchr(str, '*') < ft_strchr(str, '.')))
		{
			width = malloc(sizeof(int));
			if (!width)
				return ;
			*width = va_arg(argl, int);
		}
		if (ft_strchr(str, '.') && ft_strchr(ft_strchr(str, '.'), '*'))
		{
			precision = malloc(sizeof(int));
			if (!precision)
				return ;
			*precision = va_arg(argl, int);
		}
	}
	//write(1, "1", 1);
	formated = get_radix(*(str + ft_strlen(str) - 1), argl);
	//write(1, "2", 1);
	formated = set_precision(formated, str, precision);
	//write(1, "3", 1);
	formated = set_width(formated, str, width);
	//write(1, "4", 1);
	write(1, formated, ft_strlen(formated));
}

char	*get_radix(char type, va_list argl)
{
	char	*radix;

	radix = NULL;
	if (type == 'c')
		radix = ft_ctoa(va_arg(argl, int));
	else if (type == 's')
		radix = va_arg(argl, char *);
	else if (type == 'p')
		radix = ft_itoa_base((long)va_arg(argl, void *), "0123456789abcdef");
	else if (type == 'd')
		radix = ft_ftoa_base(va_arg(argl, double), "0123456789");
	else if (type == 'i')
		radix = ft_itoa_base(va_arg(argl, int), "0123456789");
	else if (type == 'u')
		radix = ft_utoa_base(va_arg(argl, int), "0123456789");
	else if (type == 'x')
		radix = ft_utoa_base(va_arg(argl, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		radix = ft_utoa_base(va_arg(argl, unsigned int), "0123456789ABCDEF");
	return (radix);
}

char	*set_width(char *formated, char *str, int *width)
{
	size_t	i;
	char	*placeholder;
	char	*flags;

	i = -1;
	flags = ft_strdup("\0");
	if (!width)
	{
		while (ft_strchr("-+0 ", *(str + ++i)))
			flags = ft_strjoin(flags, ft_ctoa(*(str + i)));
		str = ft_substr(str, i, ft_strlen(str) - i);
		i = 0;
		while ('0' <= *(str + i) && *(str + i) <= '9')
			i++;
		if (i == 0)
			return (formated);
		width = malloc(sizeof(int));
		if (!width)
			return (NULL);
		*width = ft_atoi(ft_substr(str, 0, i));
	}
	if (ft_strchr(flags, '+') && ft_strchr("dixX", *(str + ft_strlen(str) - 1))
		&& *formated != '-')
		formated = ft_strjoin("+", formated);
	else if (ft_strchr(flags, ' ') && !(ft_strchr("+-", *formated))
		&& ft_strchr("dixX", *(str + ft_strlen(str) - 1)))
		formated = ft_strjoin(" ", formated);
	placeholder = " ";
	if (ft_strchr(flags, '0') && ft_strchr("diuxX", *(str + ft_strlen(str) - 1))
		&& !(ft_strchr(flags, '-')))
		placeholder = "0";
	while (ft_strlen(formated) < (size_t) * width)
	{
		if (ft_strchr(flags, '-'))
			formated = ft_strjoin(placeholder, formated);
		else
			formated = ft_strjoin(formated, placeholder);
	}
	return (formated);
}

char	*set_precision(char *formated, char *str, int *precision)
{
	size_t	i;

	if (!precision)
	{
		str = ft_strchr(str, '.');
		if (!str)
			return (formated);
		str++;
		i = 0;
		while (*(str + i) && '0' <= *(str + i) && *(str + i) <= '9')
			i++;
		precision = malloc(sizeof(int));
		if (!precision)
			return (NULL);
		
		if (i == 0)
			*precision = 6;
		else
			*precision = ft_atoi(ft_substr(str, 0, i));
	}
	if (ft_strchr("sd", *(str + ft_strlen(str) - 1)))
		formated = ft_round(formated, *precision, *(str + ft_strlen(str) - 1));
	return (formated);
}
