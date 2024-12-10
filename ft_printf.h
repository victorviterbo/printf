/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:01:16 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/30 19:24:26 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
size_t	print_format(const char **str, va_list argl);
char	*get_radix(char type, va_list argl);
char	*set_width(char *formated, char *str, int *width);
char	*set_precision(char *formated, char *str, int *precision);
int		ft_atoi(const char *str);
char	*ft_utoa_base(unsigned long number, char *base);
size_t	get_usize(unsigned long n, int base_size);
char	*ft_ctoa(char c);
char	*ft_itoa_base(long long n, char *base);
size_t	get_log(size_t n, size_t base_size);
size_t	get_size(long long n, int base_size);
size_t	handle_neg(long long *number, char *number_str);
char	*ft_strjoin(char const *s1, char const *s2, int in_place);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1, int null);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif
