/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:50:00 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/20 12:50:00 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (len);
}
