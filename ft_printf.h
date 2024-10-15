/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:01:16 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/15 12:26:55 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>

# include <stdio.h>

int     ft_printf(const char *str, ...);
size_t  print_format(char *str, va_list argl);
char    *get_radix(char type, va_list argl);
char    *set_width(char *formated, char *str, int *width);
char    *set_precision(char *formated, char *str, int *precision);
int     ft_atoi(const char *str);
char    *ft_ftoa_base(double number, char *base);
char    *ft_round(char *str, int precision, char type);
char    *ft_utoa_base(long number, char *base);
char    *ft_ctoa(char c);
char    *ft_itoa_base(long n, char *base);
char    *ft_itoa_base_decimal(double number, char *base);
char    *ft_strjoin(char const *s1, char const *s2, int in_place);
char    *ft_strchr(const char *s, int c);
char    *ft_substr(char const *s, unsigned int start, size_t len);
size_t  ft_strlen(const char *str);
char    *ft_strdup(const char *s1);
void    *ft_memmove(void *dst, const void *src, size_t n);
void    *ft_calloc(size_t count, size_t size);

#endif
