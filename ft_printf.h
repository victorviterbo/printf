/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:01:16 by vviterbo          #+#    #+#             */
/*   Updated: 2024/08/22 14:55:37 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_flags{
	bool			active;
	char			flag_name;
	struct s_flag	*next;
}	t_flags;

int		ft_printf(const char *str, ...);
char	*ft_strchr(char *str, char c);
int		print_format(char *str, va_list argl);
void	set_flag(t_flags **flags, char *flag_name, bool active);
bool	get_flag(t_flags **flags, char *flag_name);
char	*ft_strchr(char *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);

#endif