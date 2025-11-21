/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-09 15:08:39 by rpinheir          #+#    #+#             */
/*   Updated: 2025-10-09 15:08:39 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int chiffre)
{
	int	count;

	count = 0;
	if (chiffre <= 0)
		count = 1;
	while (chiffre != 0)
	{
		chiffre = chiffre / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int chiffre)
{
	int		len;
	char	*string;
	long	num;

	len = ft_count(chiffre);
	string = ft_calloc(len + 1, sizeof(char));
	if (!string)
		return (NULL);
	string[len] = '\0';
	num = chiffre;
	if (num == 0)
		string[0] = '0';
	else if (num < 0)
	{
		string[0] = '-';
		num = -num;
	}
	len--;
	while (num > 0)
	{
		string[len] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (string);
}
