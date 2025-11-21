/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:54:28 by rpinheir          #+#    #+#             */
/*   Updated: 2025/10/07 08:52:48 by rpinheir         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ptr = malloc(len1 + len2 + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}
