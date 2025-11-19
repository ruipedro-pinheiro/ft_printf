/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:14:49 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/19 15:19:34 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char			*name;
	char			letter;
	int				number;
	unsigned int	num;

	name = "Marvin";
	letter = '>';
	number = 42;
	num = -256;
	ft_printf("######################################################\n");
	ft_printf("ft_printf: %c %s = %p!\n", letter, name, &name);
	printf("   printf: %c %s = %p!\n", letter, name, &name);
	ft_printf("######################################################\n");
	ft_printf("ft_printf: %i %d %u\n", number, number, num);
	printf("   printf: %i %d %u\n", number, number, num);
	ft_printf("######################################################\n");
	ft_printf("ft_printf:%x \n", number);
	printf("   printf: %x \n", number);
}

/*MAJOR BUG->
	ft_printf("ft_printf: %c%s = %p !\n", letter, name, &name);
	printf("   printf: %c%s = %p !\n", letter, name, &name);
*/
