/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:01:06 by vviterbo          #+#    #+#             */
/*   Updated: 2024/09/07 15:36:22 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...);
int		print_format(char *str, va_list argl);
char	*get_radix(char type, va_list argl);
char	*set_width(char *formated, char *str, int *width);

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
			write(1, *str + i, 1);
			i++;
			continue ;
		}
		j = i++;
		while (*(str + j) && !is_in_str(*(str + j), "cspdiuxX"))
			j++;
		print_format(ft_substr(*str, i, j + 1 - i), argl);
		i = j++;
	}
	va_end(argl);
}

int	print_format(char *str, va_list argl)
{
	t_flags	**flags;
	char	*formated;
	int		*width;
	int		*precision;

	if (ft_strchr(str, '#'))
	{
		if (ft_strchr(str, '*') < ft_strchr(str, '.'))
			*width = va_arg(argl, int);
		else
			width = NULL;
		if (ft_strchr(ft_strchr(str, '.'), '*'))
			*precision = va_arg(argl, int);
		else
			precision = NULL;
	}
	formated = get_radix(*(str + ft_strlen(str) - 1), argl);
	formated = set_width(formated, str, width);
	formated = set_precision(formated, str, precision);
}

char	*get_radix(char type, va_list argl)
{
	char	*radix;

	if (type == 'c')
		*radix = va_arg(argl, int);
	else if (type == 's')
		*radix = va_arg(argl, char *);
	else if (type == 'p')
		*radix = va_arg(argl, void *);
	else if (type == 'd')
		*radix = ft_ftoa(va_arg(argl, double));
	else if (type == 'i')
		*radix = ft_itoa_base(va_arg(argl, int), "0123456789");
	else if (type == 'u')
		*radix = ft_utoa(va_arg(argl, double));
	else if (type == 'x')
		*radix = ft_itoa_base(va_arg(argl, double), "0123456789abcdef");
	else if (type == 'X')
		*radix = ft_itoa_base(va_arg(argl, double), "0123456789ABCDEF");
	return (radix);
}

char	*set_width(char *formated, char *str, int *width)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (is_in_str('+', str) && is_in_str(*(str + ft_strlen(str) - 1), "dixX") && *formated != '-')
		formated = ft_strjoin("+", formated);
	if (!width)
	{
		while (is_in_str(*(str + i), "-+0 "))
			i++;
		j = i;
		while (0 <= *(str + j) && (str + j) <= 9)
			j++;
		*width = ft_atoi(ft_substr(str, i, j - i));
	}
	while (ft_strlen(formated) < *width)
	{
		if (is_in_str('-', str))
			formated = ft_strjoin(" ", formated);
	}
	return (formated);	
}