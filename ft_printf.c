/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:15:40 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/18 13:23:29 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int	var_handler(const char *s, int size, va_list varg)
{
	if (s[size + 1] == 'c')
		ft_putchar(va_arg(varg, int));
	if (s[size + 1] == 's')
		ft_putstr(va_arg(varg, char *));
	if (s[size + 1] == 'p')
		ft_displayptr(va_arg(varg, void *), size);
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

int	main(void)
{
	char	*name;
	char	greetings;

	name = "pedro";
	greetings = '~';
	ft_printf("ft_printf: %c Salut %s = %p !\n", greetings, name, &name);
	printf("  printf : %c Salut %s = %p !\n", greetings, name, &name);
}
