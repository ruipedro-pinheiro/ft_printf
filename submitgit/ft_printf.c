/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:15:40 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/21 11:19:08 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gère les conversions de format (%%,%c,%s,%p,%d,%i,%u,%x,%X)
** @param s: chaîne de format avec '%' à l'index i
** @param i: position actuelle sur le '%'
** @param varg: liste d'arguments variables
** @param count: nombre de caractères déjà imprimés
** Fonction: Check s[i+1] pour déterminer le type et appelle va_arg()
** pour extraire l'argument correspondant puis l'afficher
*/
int	var_handler(const char *s, int i, va_list varg, int count)
{
	if (s[i + 1] == '%')
		count += ft_putchar('%');
	else if (s[i + 1] == 'c')
		count += ft_putchar(va_arg(varg, int));
	else if (s[i + 1] == 's')
		count += ft_putstr(va_arg(varg, char *));
	else if (s[i + 1] == 'p')
		count += ft_displayptr(va_arg(varg, void *));
	else if ((s[i + 1] == 'i') || s[i + 1] == 'd')
		count += ft_putnbr(va_arg(varg, int));
	else if (s[i + 1] == 'u')
		count += ft_putnbr_unsigned(va_arg(varg, unsigned int));
	else if (s[i + 1] == 'x')
		count += ft_putnbr_hex_lowercase(va_arg(varg, unsigned int));
	else if (s[i + 1] == 'X')
		count += ft_putnbr_hex_uppercase(va_arg(varg, unsigned int));
	return (count);
}

/*
** Reproduction de printf avec formats variables (variadic function)
** @param s: chaîne de format avec spécificateurs %X
** @param ...: arguments variables correspondant aux %X
** Fonction: Parse la chaîne, si '%' trouvé appelle var_handler(),
** sinon affiche le caractère normalement. Retourne le nombre total
** de caractères imprimés (comme printf original)
*/
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
