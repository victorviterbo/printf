/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:01:06 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/15 20:31:47 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...);
size_t	print_format(char *str, va_list argl);
char	*get_radix(char type, va_list argl);
char	*set_width(char *formated, char *str, int *width);
char	*set_precision(char *formated, char *str, int *precision);

int	ft_printf(const char *str, ...)
{
	size_t	printed;
	size_t	i;
	size_t	j;
	va_list	argl;

	printed = 0;
	i = 0;
	va_start(argl, str);
	while (*(str + i))
	{
		if (*(str + i) != '%' || (*(str + i) == '%' && *(str + i + 1) == '%'))
		{
			i += (*(str + i) == '%');
			if (write(1, (str + i), 1) != -1)
				printed++;
			i++;
			continue ;
		}
		j = ++i;
		while (*(str + j - 1) && !ft_strchr("cspdiuxX", *(str + j - 1)))
			j++;
		printed += print_format(ft_substr(str, i, j - i), argl);
		i = j;
	}
	va_end(argl);
	return (printed);
}

size_t	print_format(char *str, va_list argl)
{
	char	*formated;
	int		*width;
	int		*precision;
	long	printed;

	width = NULL;
	precision = NULL;
	printed = 0;
	if (!str)
		return (0);
	if (ft_strchr(str, '*'))
	{
		if (!ft_strchr(str, '.') || (ft_strchr(str, '*') < ft_strchr(str, '.')))
		{
			width = ft_calloc(1, sizeof(int));
			if (!width)
				return (0);
			*width = va_arg(argl, int);
		}
		if (ft_strchr(str, '.') && ft_strchr(ft_strchr(str, '.'), '*'))
		{
			precision = ft_calloc(1, sizeof(int));
			if (!precision)
				return (0);
			*precision = va_arg(argl, int);
		}
	}
	formated = get_radix(*(str + ft_strlen(str) - 1), argl);
	formated = set_precision(formated, str, precision);
	formated = set_width(formated, str, width);
	if (ft_strlen(formated) > 0)
		printed = write(1, formated, ft_strlen(formated));
	else if (*(str + ft_strlen(str) - 1) == 'c')
		printed = write(1, formated, 1);
	if (printed < 0)
		printed = 0;
	free(str);
	free(formated);
	return (printed);
}

char	*get_radix(char type, va_list argl)
{
	char	*radix;

	radix = NULL;
	if (type == 'c')
		radix = ft_ctoa(va_arg(argl, int));
	else if (type == 's')
	{
		radix = ft_strdup(va_arg(argl, char *));
		if (!radix)
			return (ft_strdup("(null)"));
	}
	else if (type == 'p')
		radix = ft_strjoin("0x", ft_utoa_base((long)va_arg(argl, void *),
					"0123456789abcdef"), 2);
	else if (type == 'd')
		radix = ft_itoa_base(va_arg(argl, int), "0123456789");
	else if (type == 'i')
		radix = ft_itoa_base(va_arg(argl, int), "0123456789");
	else if (type == 'u')
		radix = ft_utoa_base((unsigned int)va_arg(argl, int), "0123456789");
	else if (type == 'x')
		radix = ft_itoa_base(va_arg(argl, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		radix = ft_itoa_base(va_arg(argl, unsigned int), "0123456789ABCDEF");
	return (radix);
}

char	*set_width(char *formated, char *str, int *width)
{
	size_t	i;
	char	*placeholder;
	char	*flags;

	i = -1;
	flags = ft_strdup("\0");
	if (!flags)
		return (NULL);
	if (!width)
	{
		while (ft_strchr("-+0 ", *(str + ++i)))
			flags = ft_strjoin(flags, ft_ctoa(*(str + i)), 1);
		str += i;
		i = 0;
		while ('0' <= *(str + i) && *(str + i) <= '9')
			i++;
		if (i == 0)
		{
			free(flags);
			return (formated);
		}
		width = ft_calloc(1, sizeof(int));
		if (!width)
		{
			free(flags);
			return (NULL);
		}
		*width = ft_atoi(ft_substr(str, 0, i));
	}
	if (ft_strchr(flags, '+') && ft_strchr("dixX", *(str + ft_strlen(str) - 1))
		&& *formated != '-')
		formated = ft_strjoin("+", formated, 2);
	else if (ft_strchr(flags, ' ') && !(ft_strchr("+-", *formated))
		&& ft_strchr("dixX", *(str + ft_strlen(str) - 1)))
		formated = ft_strjoin(" ", formated, 2);
	placeholder = " ";
	if (ft_strchr(flags, '0') && ft_strchr("dixX", *(str + ft_strlen(str) - 1))
		&& !(ft_strchr(flags, '-')) && !(ft_strchr(str, '.')))
		placeholder = "0";
	while (ft_strlen(formated) < (size_t) * width)
	{
		if (ft_strchr(flags, '-'))
			formated = ft_strjoin(formated, placeholder, 1);
		else
			formated = ft_strjoin(placeholder, formated, 2);
	}
	free(flags);
	free(width);
	return (formated);
}

char	*set_precision(char *formated, char *str, int *precision)
{
	size_t	i;
	char	*truncated;

	if (!precision)
	{
		str = ft_strchr(str, '.');
		if (!str)
			return (formated);
		str++;
		i = 0;
		while (*(str + i) && '0' <= *(str + i) && *(str + i) <= '9')
			i++;
		precision = ft_calloc(1, sizeof(int));
		if (!precision)
			return (NULL);
		if (i == 0)
			*precision = 6;
		else
			*precision = ft_atoi(ft_substr(str, 0, i));
	}
	if (*(str + ft_strlen(str) - 1) == 's')
	{
		truncated = ft_substr(formated, 0, *precision);
		free(formated);
		return (truncated);
	}
	free(precision);
	return (formated);
}
