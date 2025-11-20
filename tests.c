/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:40:00 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/21 00:40:00 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

extern int	g_pass;
extern int	g_fail;

/*
** Compare les valeurs de retour et affiche le résultat
** @param name: nom du test (ex: "%c", "%s")
** @param r1: valeur de retour de ft_printf
** @param r2: valeur de retour de printf (référence)
** Fonction: Compare r1 et r2, affiche OK (vert) si égaux ou KO (rouge)
** si différents, puis incrémente g_pass ou g_fail
*/
void	test_result(char *name, int r1, int r2)
{
	ft_printf("\n  [%s] Return: %d vs %d -> ", name, r1, r2);
	if (r1 == r2)
	{
		ft_printf("\033[1;32mOK\033[0m\n");
		g_pass++;
	}
	else
	{
		ft_printf("\033[1;31mKO\033[0m\n");
		g_fail++;
	}
}

/*
** Execute les tests de base pour %c et %s
** Fonction: Tests de caractères et chaînes (normal + NULL)
*/
void	test_char_string(void)
{
	int		r1;
	int		r2;
	char	*null;

	null = NULL;
	ft_printf("\n  Test %%c with 'A':");
	ft_printf("\n  ft_printf: |");
	r1 = ft_printf("%c", 'A');
	ft_printf("|");
	printf("\n  printf:    |");
	r2 = printf("%c", 'A');
	printf("|");
	fflush(stdout);
	test_result("%c", r1, r2);
	ft_printf("\n  Test %%s with \"Hello\":");
	ft_printf("\n  ft_printf: |");
	r1 = ft_printf("%s", "Hello");
	ft_printf("|");
	printf("\n  printf:    |");
	r2 = printf("%s", "Hello");
	printf("|");
	fflush(stdout);
	test_result("%s", r1, r2);
	ft_printf("\n  Test %%s (NULL):");
	ft_printf("\n  ft_printf: |");
	r1 = ft_printf("%s", null);
	ft_printf("|");
	printf("\n  printf:    |");
	r2 = printf("%s", null);
	printf("|");
	fflush(stdout);
	test_result("%s NULL", r1, r2);
}

/*
** Execute les tests pour %p (pointeurs)
** Fonction: Tests de pointeurs (adresse + NULL)
*/
void	test_pointer(void)
{
	int	r1;
	int	r2;

	ft_printf("\n  Test %%p with &r1:");
	ft_printf("\n  ft_printf: |");
	r1 = ft_printf("%p", &r1);
	ft_printf("|");
	printf("\n  printf:    |");
	r2 = printf("%p", &r1);
	printf("|");
	fflush(stdout);
	test_result("%p", r1, r2);
	ft_printf("\n  Test %%p (NULL):");
	ft_printf("\n  ft_printf: |");
	r1 = ft_printf("%p", NULL);
	ft_printf("|");
	printf("\n  printf:    |");
	r2 = printf("%p", NULL);
	printf("|");
	fflush(stdout);
	test_result("%p NULL", r1, r2);
}

/*
** Execute les tests pour %d, %i et %u
** Fonction: Tests d'entiers signés et non-signés
*/
void	test_integers(void)
{
	int	r1;
	int	r2;

	ft_printf("\n  Test %%d with 42:");
	ft_printf("\n  ft_printf: |");
	r1 = ft_printf("%d", 42);
	ft_printf("|");
	printf("\n  printf:    |");
	r2 = printf("%d", 42);
	printf("|");
	fflush(stdout);
	test_result("%d", r1, r2);
	ft_printf("\n  Test %%d with -42:");
	ft_printf("\n  ft_printf: |");
	r1 = ft_printf("%d", -42);
	ft_printf("|");
	printf("\n  printf:    |");
	r2 = printf("%d", -42);
	printf("|");
	fflush(stdout);
	test_result("%d neg", r1, r2);
	ft_printf("\n  Test %%d with INT_MIN:");
	ft_printf("\n  ft_printf: |");
	r1 = ft_printf("%d", INT_MIN);
	ft_printf("|");
	printf("\n  printf:    |");
	r2 = printf("%d", INT_MIN);
	printf("|");
	fflush(stdout);
	test_result("%d MIN", r1, r2);
	ft_printf("\n  Test %%i with 123:");
	ft_printf("\n  ft_printf: |");
	r1 = ft_printf("%i", 123);
	ft_printf("|");
	printf("\n  printf:    |");
	r2 = printf("%i", 123);
	printf("|");
	fflush(stdout);
	test_result("%i", r1, r2);
	ft_printf("\n  Test %%u with UINT_MAX:");
	ft_printf("\n  ft_printf: |");
	r1 = ft_printf("%u", UINT_MAX);
	ft_printf("|");
	printf("\n  printf:    |");
	r2 = printf("%u", UINT_MAX);
	printf("|");
	fflush(stdout);
	test_result("%u", r1, r2);
}

/*
** Execute les tests pour %x, %X et %%
** Fonction: Tests hexadécimaux et pourcentage littéral
*/
void	test_hex_percent(void)
{
	int	r1;
	int	r2;

	ft_printf("\n  Test %%x with 255:");
	ft_printf("\n  ft_printf: |");
	r1 = ft_printf("%x", 255);
	ft_printf("|");
	printf("\n  printf:    |");
	r2 = printf("%x", 255);
	printf("|");
	fflush(stdout);
	test_result("%x", r1, r2);
	ft_printf("\n  Test %%X with 255:");
	ft_printf("\n  ft_printf: |");
	r1 = ft_printf("%X", 255);
	ft_printf("|");
	printf("\n  printf:    |");
	r2 = printf("%X", 255);
	printf("|");
	fflush(stdout);
	test_result("%X", r1, r2);
	ft_printf("\n  Test %%%% (literal %%):");
	ft_printf("\n  ft_printf: |");
	r1 = ft_printf("%%");
	ft_printf("|");
	printf("\n  printf:    |");
	r2 = printf("%%");
	printf("|");
	fflush(stdout);
	test_result("%%", r1, r2);
}
