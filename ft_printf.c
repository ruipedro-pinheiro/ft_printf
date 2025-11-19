/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:15:40 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/19 15:16:07 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* TODO: FOUND A MAJOR BUG
	IF THERE ARE TWO OR MORE ARGS IN PRINTF FOLLOWING EACH OTHER WITHOUT SPACE
		IT DOESNT WORK LIKE IN PRINTF
*/
int	var_handler(const char *s, int size, va_list varg)
{
	if (s[size + 1] == 'c')
		ft_putchar(va_arg(varg, int));
	if (s[size + 1] == 's')
		ft_putstr(va_arg(varg, char *));
	if (s[size + 1] == 'p')
		ft_displayptr(va_arg(varg, void *), size);
	if ((s[size + 1] == 'i') || s[size + 1] == 'd')
		ft_putnbr(va_arg(varg, int));
	if (s[size + 1] == 'u')
		ft_putnbr_unsigned(va_arg(varg, unsigned int), size);
	if (s[size + 1] == 'x')
		ft_putnbr_hex_x((va_arg(varg, unsigned int)), size);
	/*if (s[size + 1] == 'X')
		ft_putnbr_hex_X((va_arg(varg, unsigned int), size));*/
	return (size);
}

int	ft_printf(const char *s, ...)
{
	int		size;
	va_list	varg;

	va_start(varg, s);
	size = 0;
	while (s[size] != '\0')
	{
		if (s[size] == '%')
		{
			if (s[size + 1] == '%')
			{
				ft_putchar('%');
				size++;
			}
			else
			{
				var_handler(s, size, varg);
				size += 2;
			}
		}
		if (s[size] != '%')
			ft_putchar(s[size]);
		size++;
	}
	return (size);
}
