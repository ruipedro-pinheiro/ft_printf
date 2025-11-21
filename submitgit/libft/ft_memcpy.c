/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:06:52 by rpinheir          #+#    #+#             */
/*   Updated: 2025/10/06 09:35:13 by rpinheir         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	if (!dest && !src)
		return (NULL);
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	while (n--)
		*(tmp_dest++) = *(tmp_src++);
	return (dest);
}
