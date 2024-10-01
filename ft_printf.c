/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:01:06 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/01 10:38:28 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...);
int		print_format(char *str, va_list argl);
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
		printf("str = %s, i = %zu, j = %zu\n", ft_substr(str, i, j - i), i, j);
		print_format(ft_substr(str, i, j - i), argl);
		i = j;
	}
	va_end(argl);
	return (1);
}

int	print_format(char *str, va_list argl)
{
	char	*formated;
	int		*width;
	int		*precision;

	if (ft_strchr(str, '*'))
	{
		if (!ft_strchr(str, '.') || (ft_strchr(str, '*') < ft_strchr(str, '.')))
		{
			width = malloc(sizeof(int));
			if (!width)
				return (-1);
			*width = va_arg(argl, int);
			printf("getting width from var %i\n", *width);
		}
		else
			width = NULL;
		if (ft_strchr(str, '.') && ft_strchr(ft_strchr(str, '.'), '*'))
		{
			precision = malloc(sizeof(int));
			if (!precision)
				return (-1);
			*precision = va_arg(argl, int);
			printf("getting precision from var %i\n", *precision);
		}
		else
			precision = NULL;
	}
	else
	{
		precision = NULL;
		width = NULL;
	}
	printf("width = %p, precision = %p\n", width, precision);
	formated = get_radix(*(str + ft_strlen(str) - 1), argl);
	printf("formated after radix = %s,\n", formated);
	formated = set_precision(formated, str, precision);
	printf("formated after precision = %s,\n", formated);
	formated = set_width(formated, str, width);
	printf("formated after width = %s,\n", formated);
	write(1, formated, ft_strlen(formated));
	return (0);
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
		radix = va_arg(argl, void *);
	else if (type == 'd')
		radix = ft_ftoa_base(va_arg(argl, double), "0123456789");
	else if (type == 'i')
		radix = ft_itoa_base(va_arg(argl, int), "0123456789");
	else if (type == 'u')
		*radix = ft_utoa(va_arg(argl, double));
	else if (type == 'x')
		radix = ft_ftoa_base(va_arg(argl, double), "0123456789abcdef");
	else if (type == 'X')
		radix = ft_ftoa_base(va_arg(argl, double), "0123456789ABCDEF");
	return (radix);
}

char	*set_width(char *formated, char *str, int *width)
{
	size_t	i;
	char	*placeholder;
	char	*flags;

	i = 0;

	flags = ft_strdup("\0");
	if (!width)
	{
		while (ft_strchr("-+0 ", *(str + i)))
		{
			flags = ft_strjoin(flags, ft_ctoa(*(str + i)));
			i++;
		}
		str = ft_substr(str, i, ft_strlen(str) - i);
		i = 0;
		while ('0' <= *(str + i) && *(str + i) <= '9')
			i++;
		if (i == 0)
			return (formated);
		width = malloc(sizeof(int));
		*width = ft_atoi(ft_substr(str, 0, i));
	}
	if (ft_strchr(flags, '+') && ft_strchr("dixX", *(str + ft_strlen(str) - 1))
		&& *formated != '-')
		formated = ft_strjoin("+", formated);
	else if (ft_strchr(flags, ' ')
		&& ft_strchr("dixX", *(str + ft_strlen(str) - 1)) && *formated != '-')
		formated = ft_strjoin(" ", formated);
	if (ft_strchr(flags, '0') && ft_strchr("dixX", *(str + ft_strlen(str) - 1))
		&& !(ft_strchr(flags, '-') && *(str + ft_strlen(str) - 1) == 'i'))
		placeholder = "0";
	else
		placeholder = " ";
	printf("width = %i\n", *width);
	while (ft_strlen(formated) < (size_t)*width)
	{
		printf("formated = %s, placeholder = >%s<\n", formated, placeholder);
		if (ft_strchr(flags, '-'))
			formated = ft_strjoin(placeholder, formated);
		else
			formated = ft_strjoin(formated, placeholder);
		printf("new formated = %s, placeholder = >%s<\n", formated, placeholder);
	}
	return (formated);
}

char	*set_precision(char *formated, char *str, int *precision)
{
	size_t	i;

	if (!precision)
	{
		printf("\n HELLO \n");
		str = ft_strchr(str, '.');
		printf("str in formated = %p\n", str);
		if (!str)
			return (formated);
		str++;
		printf("new str >%c< \n", *(str));
		i = 0;
		while (*(str + i) && '0' <= *(str + i) && *(str + i) <= '9')
			i++;
		printf("i = %zu\n", i);
		if (i == 0)
			return (formated);
		precision = malloc(sizeof(int));
		if (!precision)
			return (NULL);
		*precision = ft_atoi(ft_substr(str, 0, i));
	}
	printf("precision is now %i", *precision);
	if (ft_strchr("duxX", *(str + ft_strlen(str) - 1)))
	{
		formated = ft_round(formated, *precision, *(str + ft_strlen(str) - 1));
	}
	return (formated);
}
