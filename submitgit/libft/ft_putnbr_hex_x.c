/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:38:40 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/19 15:53:19 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hex_x(unsigned int n, int size)
{
	char	*res;

	res = 0;
	if (n == 0)
	{
		return (ft_putchar('0'), size++);
	}
	else
	{
		if ((char)n > 9)
		{
			res = '0' + n;
		}
		else
		{
			res = '0' + n;
			size++;
		}
	}
	write(1, &n, 1);
	return (size);
}
