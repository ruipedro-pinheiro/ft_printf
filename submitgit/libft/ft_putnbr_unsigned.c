/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:02:17 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/18 17:07:05 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_unsigned(unsigned int n, int size)
{
	int	num;

	num = 0;
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10, size);
		ft_putnbr_unsigned(n % 10, size);
	}
	else
	{
		num = n + '0';
		write(1, &num, 1);
	}
	return (size);
}
