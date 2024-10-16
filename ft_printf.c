/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:01:06 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/16 16:45:41 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...);
size_t	print_format(char *str, va_list argl);
char	*get_radix(char type, va_list argl);
char	*set_width(char *formated, char *str, int *width);
char	*set_precision(char *formated, char *str, int *precision);
size_t	set_flags(char *str, char **flags, char *formated);

int	ft_printf(const char *str, ...)
{
	size_t	printed;
	size_t	i;
	va_list	argl;

	printed = 0;
	if (!str)
		return (NULL);
	va_start(argl, str);
	while (*(str))
	{
		if (*(str) != '%')
		{
			if (write(1, (str), 1) != -1)
				printed++;
			str++;
			continue ;
		}
		i = 1;
		while (*(str + i) && !ft_strchr("cspdiuxX%", *(str + i)))
			i++;
		printed += print_format(ft_substr(str, 0, i + 1), argl);
		str += i + 1;
	}
	va_end(argl);
	return (printed);
}

size_t	print_format(char *str, va_list argl)
{
	char	*formated;
	long	printed;

	printed = 0;
	formated = get_radix(*(str + ft_strlen(str) - 1), argl);
	if (ft_strlen(formated))
		printed = write(1, formated, ft_strlen(formated));
	else if (*(str + ft_strlen(str) - 1) == 'c')
		printed = write(1, formated, 1);
	return (free(str), free(formated), printed);
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
	else if (type == '%')
		radix = ft_ctoa('%');
	return (radix);
}
