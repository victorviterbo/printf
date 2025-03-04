/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:34:17 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/30 18:25:03 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2, int in_place);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1, int null);

char	*ft_strjoin(char const *s1, char const *s2, int in_place)
{
	char	*joined;

	joined = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!joined || !s1 || !s2)
	{
		if (in_place == 1 || in_place == 3)
			free((void *)s1);
		else if (in_place == 2 || in_place == 3)
			free((void *)s2);
		if (joined)
			free(joined);
		return (NULL);
	}
	ft_memmove(joined, s1, ft_strlen(s1));
	ft_memmove(joined + ft_strlen(s1), s2, ft_strlen(s2));
	*(joined + ft_strlen(s1) + ft_strlen(s2)) = '\0';
	if (in_place == 1 || in_place == 3)
		free((void *)s1);
	else if (in_place == 2 || in_place == 3)
		free((void *)s2);
	return (joined);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	while (*(s + i))
	{
		if ((unsigned char)*(s + i) == uc)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	else
		return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	substr = ft_calloc((len + 1), sizeof(char));
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strdup(const char *s1, int null)
{
	char	*duplicate;

	if (!s1 && null)
		return (ft_strdup("(null)", 0));
	if (!s1)
		return (NULL);
	duplicate = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!duplicate)
		return (NULL);
	ft_memmove(duplicate, s1, ft_strlen(s1) + 1);
	return (duplicate);
}
