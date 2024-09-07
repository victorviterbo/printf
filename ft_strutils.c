/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:34:17 by vviterbo          #+#    #+#             */
/*   Updated: 2024/09/07 12:45:18 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(char *str, char c);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*joined;
	unsigned int	i;
	unsigned int	j;

	joined = malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)
			* sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	j = 0;
	while (*(s1 + i))
	{
		*(joined + j) = *(s1 + i);
		i++;
		j++;
	}
	i = 0;
	while (*(s2 + i))
	{
		*(joined + j) = *(s2 + i);
		i++;
		j++;
	}
	return (joined);
}

char	*ft_strchr(char *str, char c)
{
	size_t	i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == c)
			return (str + i);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	substr = malloc(len * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && *(s + start + i))
	{
		*(substr + i) = *(s + start + i);
		i++;
	}
	*(substr + i) = '\0';
	return (substr);
}
