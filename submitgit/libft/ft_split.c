/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-09 12:22:53 by rpinheir          #+#    #+#             */
/*   Updated: 2025-10-09 12:22:53 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count(const char *s, char c, int count)
{
	int	inword;
	int	i;

	i = 0;
	inword = 0;
	while (s[i])
	{
		if (s[i] != c && !inword)
		{
			count++;
			inword = 1;
		}
		else if (s[i] == c)
		{
			inword = 0;
		}
		i++;
	}
	return (count);
}

static char	**ft_free(char **ptr, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

static char	*ft_stringmanager(const char *s, char c, int start)
{
	int		len;
	char	*string;
	int		i;

	len = 0;
	while (s[start + len] && s[start + len] != c)
	{
		len++;
	}
	string = ft_calloc(len + 1, sizeof(char));
	if (!string)
		return (NULL);
	i = 0;
	while (i < len)
	{
		string[i] = s[start + i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	count = ft_count(s, c, 0);
	ptr = ft_calloc(count + 1, sizeof(char *));
	if (!ptr)
		return (NULL);
	while (i < count)
	{
		while (s[j] == c)
			j++;
		ptr[i] = ft_stringmanager(s, c, j);
		if (!ptr[i])
			return (ft_free(ptr, i));
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
