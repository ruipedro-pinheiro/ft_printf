/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_uppercase.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:53:00 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/20 13:58:56 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hex_uppercase(unsigned int n)
{
	char	*base;
	int		count;

	base = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
	{
		count += ft_putnbr_hex_uppercase(n / 16);
		count += ft_putnbr_hex_uppercase(n % 16);
	}
	else
	{
		write(1, &base[n], 1);
		count++;
	}
	return (count);
}
