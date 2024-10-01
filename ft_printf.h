/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:01:16 by vviterbo          #+#    #+#             */
/*   Updated: 2024/09/25 16:25:40 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>

#include <stdio.h>

int				ft_printf(const char *str, ...);
int				print_format(char *str, va_list argl);
char			*get_radix(char type, va_list argl);
char			*set_width(char *formated, char *str, int *width);
char			*set_precision(char *formated, char *str, int *precision);
char			*ft_itoa_base(int n, char *base);
char			*ft_itoa_base_decimal(double n, char *base);
int				ft_atoi(const char *str);
char			*ft_ftoa_base(double number, char *base);
char			*ft_round(char *str, int precision, char type);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strchr(char *str, char c);
size_t			ft_strlen(char *str);
char			*ft_ctoa(char c);
char			*ft_strdup(const char *s1);

#endif