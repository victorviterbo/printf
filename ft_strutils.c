/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:34:17 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/10 13:03:38 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup_pf(const char *s1, int null);

char	*ft_strdup_pf(const char *s1, int null)
{
	char	*duplicate;

	if (!s1 && null)
		return (ft_strdup_pf("(null)", 0));
	if (!s1)
		return (NULL);
	duplicate = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!duplicate)
		return (NULL);
	ft_memmove(duplicate, s1, ft_strlen(s1) + 1);
	return (duplicate);
}
