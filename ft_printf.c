/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:15:40 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/20 13:55:46 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* TODO: FOUND A MAJOR BUG
	IF THERE ARE TWO OR MORE ARGS IN PRINTF FOLLOWING EACH OTHER WITHOUT SPACE
		IT DOESNT WORK LIKE IN PRINTF
*/
int	var_handler(const char *s, int i, va_list varg, int count)
{
	if (s[i + 1] == '%')
		count += ft_putchar('%');
	if (s[i + 1] == 'c')
		count += ft_putchar(va_arg(varg, int));
	if (s[i + 1] == 's')
		count += ft_putstr(va_arg(varg, char *));
	if (s[i + 1] == 'p')
		count += ft_displayptr(va_arg(varg, void *));
	if ((s[i + 1] == 'i') || s[i + 1] == 'd')
		count += ft_putnbr(va_arg(varg, int));
	if (s[i + 1] == 'u')
		count += ft_putnbr_unsigned(va_arg(varg, unsigned int));
	if (s[i + 1] == 'x')
		count += ft_putnbr_hex_lowercase(va_arg(varg, unsigned int));
	if (s[i + 1] == 'X')
		count += ft_putnbr_hex_uppercase(va_arg(varg, unsigned int));
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	int		i;
	va_list	varg;

	va_start(varg, s);
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			count = var_handler(s, i, varg, count);
			i += 2;
			continue ;
		}
		if (s[i] != '%')
			count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}
