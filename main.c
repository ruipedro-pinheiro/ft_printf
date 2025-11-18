/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:14:49 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/18 15:34:09 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	*name;
	char	letter;

	name = "Marvin";
	letter = '>';
	ft_printf("ft_printf: %c %s = %p !\n", letter, name, &name);
	printf("   printf: %c %s = %p !\n", letter, name, &name);
}
/*MAJOR BUG->
	ft_printf("ft_printf: %c%s = %p !\n", letter, name, &name);
	printf("   printf: %c%s = %p !\n", letter, name, &name);
*/
