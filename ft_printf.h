/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:01:16 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/10 14:15:01 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft.h"

int		ft_printf(const char *str, ...);
size_t	print_format(const char **str, va_list argl);
char	*get_radix(char type, va_list argl);
char	*ft_utoa_base(unsigned long number, char *base);
char	*ft_itoa_base(long long n, char *base);
char	*ft_strdup_pf(const char *s1, int null);

#endif
