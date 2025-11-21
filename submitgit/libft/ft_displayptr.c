/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displayptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:54:00 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/20 12:54:00 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putptr_hex(unsigned long n)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count += ft_putptr_hex(n / 16);
		count += ft_putptr_hex(n % 16);
	}
	else
	{
		write(1, &base[n], 1);
		count++;
	}
	return (count);
}

int	ft_displayptr(void *ptr)
{
	int				count;
	unsigned long	address;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	address = (unsigned long)ptr;
	count = 0;
	write(1, "0x", 2);
	count += 2;
	count += ft_putptr_hex(address);
	return (count);
}
