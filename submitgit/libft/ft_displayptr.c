/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displayptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 09:24:11 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/18 13:21:03 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_displayptr(void *ptr, int size)
{
	unsigned long	i;
	unsigned long	addr;
	char			buffer[sizeof(unsigned long) * 2];
	int				d;

	i = 0;
	addr = (unsigned long)ptr;
	ft_putchar('0');
	ft_putchar('x');
	if (addr == 0)
	{
		return (ft_putchar('0'), size++);
	}
	while (addr != 0)
	{
		d = addr & 0xF;
		if ((char)d < 10)
			buffer[i++] = '0' + d;
		else
			buffer[i++] = 'a' + (d - 10);
		addr >>= 4;
	}
	while (i-- > 0)
		ft_putchar(buffer[i]);
	return (size += i);
}
