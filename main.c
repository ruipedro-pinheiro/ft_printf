/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:14:49 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/21 00:45:00 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	g_pass;
int	g_fail;

void	test_result(char *name, int r1, int r2);
void	test_char_string(void);
void	test_pointer(void);
void	test_integers(void);
void	test_hex_percent(void);

/*
** Fonction principale du testeur
** Fonction: Initialise les compteurs, lance tous les tests,
** affiche le résumé final et retourne le nombre d'échecs
*/
int	main(void)
{
	g_pass = 0;
	g_fail = 0;
	ft_printf("\n  ===== FT_PRINTF TESTER =====\n");
	test_char_string();
	test_pointer();
	test_integers();
	test_hex_percent();
	ft_printf("\n\n  ========== SUMMARY ==========\n");
	ft_printf("  Passed: \033[1;32m%d\033[0m | Failed: \033[1;31m%d\033[0m\n",
		g_pass, g_fail);
	ft_printf("  =============================\n\n");
	return (g_fail);
}
