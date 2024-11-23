/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:44:34 by meandrad          #+#    #+#             */
/*   Updated: 2024/11/22 21:03:16 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *) &s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	concat = (char *)malloc((ft_strlen(s2) + ft_strlen(s1)+ 1) * sizeof(char));
	if (!concat)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		concat[i + j] = s2[j];
		j++;
	}
	concat[i + j] = '\0';
	return (concat);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
		return (ft_strdup(""));
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
