/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:45:27 by vviterbo          #+#    #+#             */
/*   Updated: 2024/08/15 12:55:06 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flag(t_flags **flags, char flag_name, bool active);
bool	get_flag(t_flags **flags, char flag_name);

void	set_flag(t_flags **flags, char flag_name, bool active)
{
	t_flags	*curr_flag;

	if (*flags)
	{
		curr_flag = *flags;
		while (curr_flag->next && curr_flag->flag_name != flag_name)
			flags = curr_flag->next;
		if (curr_flag->flag_name == flag_name)
		{
			curr_flag->active = active;
			return ;
		}
		curr_flag->next = malloc(sizeof(t_flags));
		flags = curr_flag->next;
	}
	else
	{
		curr_flag = malloc(sizeof(t_flags));
		*flags = curr_flag;
	}
	if (!(curr_flag))
		return ;
	curr_flag->flag_name = flag_name;
	curr_flag->active = active;
	curr_flag->next = NULL;
}

bool	get_flag(t_flags **flags, char flag_name)
{
	t_flags	*curr_flag;

	curr_flag = *flags;
	while (curr_flag && curr_flag->flag_name != flag_name)
		curr_flag = curr_flag->next;
	if (!curr_flag)
		return (false);
	return (curr_flag->active);
}
