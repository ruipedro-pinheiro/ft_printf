/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:14:49 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/21 01:05:00 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

/*
** Testeur pour démonstration lors de l'évaluation
** Fonction: Compare visuellement ft_printf et printf côte à côte
** pour chaque format. Montre l'output ET la valeur de retour.
*/
int	main(void)
{
	int		r1;
	int		r2;
	char	*null_ptr;

	null_ptr = NULL;
	ft_printf("\n============ FT_PRINTF TESTER ============\n\n");
	ft_printf("Test %%c avec 'A':\n");
	ft_printf("  ft_printf -> |");
	r1 = ft_printf("%c", 'A');
	ft_printf("| (ret: %d)\n", r1);
	printf("  printf    -> |%c| (ret: %d)\n", 'A', (r2 = 1));
	fflush(stdout);
	ft_printf("\n");
	ft_printf("Test %%s avec \"Hello\":\n");
	ft_printf("  ft_printf -> |");
	r1 = ft_printf("%s", "Hello");
	ft_printf("| (ret: %d)\n", r1);
	printf("  printf    -> |%s| (ret: %d)\n", "Hello", (r2 = 5));
	fflush(stdout);
	ft_printf("\n");
	ft_printf("Test %%s avec NULL:\n");
	ft_printf("  ft_printf -> |");
	r1 = ft_printf("%s", null_ptr);
	ft_printf("| (ret: %d)\n", r1);
	printf("  printf    -> |");
	r2 = printf("%s", null_ptr);
	printf("| (ret: %d)\n", r2);
	fflush(stdout);
	ft_printf("\n");
	ft_printf("Test %%p avec adresse:\n");
	ft_printf("  ft_printf -> |");
	r1 = ft_printf("%p", &r1);
	ft_printf("| (ret: %d)\n", r1);
	printf("  printf    -> |");
	r2 = printf("%p", &r1);
	printf("| (ret: %d)\n", r2);
	fflush(stdout);
	ft_printf("\n");
	ft_printf("Test %%p avec NULL:\n");
	ft_printf("  ft_printf -> |");
	r1 = ft_printf("%p", NULL);
	ft_printf("| (ret: %d)\n", r1);
	printf("  printf    -> |");
	r2 = printf("%p", NULL);
	printf("| (ret: %d)\n", r2);
	fflush(stdout);
	ft_printf("\n");
	ft_printf("Test %%d avec 42:\n");
	ft_printf("  ft_printf -> |");
	r1 = ft_printf("%d", 42);
	ft_printf("| (ret: %d)\n", r1);
	printf("  printf    -> |%d| (ret: %d)\n", 42, 2);
	fflush(stdout);
	ft_printf("\n");
	ft_printf("Test %%d avec -42:\n");
	ft_printf("  ft_printf -> |");
	r1 = ft_printf("%d", -42);
	ft_printf("| (ret: %d)\n", r1);
	printf("  printf    -> |%d| (ret: %d)\n", -42, 3);
	fflush(stdout);
	ft_printf("\n");
	ft_printf("Test %%d avec INT_MIN:\n");
	ft_printf("  ft_printf -> |");
	r1 = ft_printf("%d", INT_MIN);
	ft_printf("| (ret: %d)\n", r1);
	printf("  printf    -> |%d| (ret: %d)\n", INT_MIN, 11);
	fflush(stdout);
	ft_printf("\n");
	ft_printf("Test %%i avec 123:\n");
	ft_printf("  ft_printf -> |");
	r1 = ft_printf("%i", 123);
	ft_printf("| (ret: %d)\n", r1);
	printf("  printf    -> |%i| (ret: %d)\n", 123, 3);
	fflush(stdout);
	ft_printf("\n");
	ft_printf("Test %%u avec UINT_MAX:\n");
	ft_printf("  ft_printf -> |");
	r1 = ft_printf("%u", 4294967295u);
	ft_printf("| (ret: %d)\n", r1);
	printf("  printf    -> |%u| (ret: %d)\n", 4294967295u, 10);
	fflush(stdout);
	ft_printf("\n");
	ft_printf("Test %%x avec 255:\n");
	ft_printf("  ft_printf -> |");
	r1 = ft_printf("%x", 255);
	ft_printf("| (ret: %d)\n", r1);
	printf("  printf    -> |%x| (ret: %d)\n", 255, 2);
	fflush(stdout);
	ft_printf("\n");
	ft_printf("Test %%X avec 255:\n");
	ft_printf("  ft_printf -> |");
	r1 = ft_printf("%X", 255);
	ft_printf("| (ret: %d)\n", r1);
	printf("  printf    -> |%X| (ret: %d)\n", 255, 2);
	fflush(stdout);
	ft_printf("\n");
	ft_printf("Test %%%% (literal):\n");
	ft_printf("  ft_printf -> |");
	r1 = ft_printf("%%");
	ft_printf("| (ret: %d)\n", r1);
	printf("  printf    -> |%%| (ret: %d)\n", 1);
	fflush(stdout);
	ft_printf("\n");
	ft_printf("Test complexe \"%%s a %%d pts\":\n");
	ft_printf("  ft_printf -> |");
	r1 = ft_printf("%s a %d pts", "Test", 42);
	ft_printf("| (ret: %d)\n", r1);
	printf("  printf    -> |");
	r2 = printf("%s a %d pts", "Test", 42);
	printf("| (ret: %d)\n", r2);
	fflush(stdout);
	ft_printf("\n==========================================\n\n");
	return (0);
}
