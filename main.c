/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:14:49 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/20 14:22:04 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	test_section(char *title)
{
	ft_printf("\n\033[1;35m━━━ %s ━━━\033[0m\n", title);
}

void	test_basic(void)
{
	int	ret_ft;
	int	ret_og;

	test_section("printf(\"%c %s %p\", 'A', \"test\", &var)");
	ret_ft = ft_printf("%c %s %p\n", 'A', "test", &ret_ft);
	ret_og = printf("%c %s %p\n", 'A', "test", &ret_og);
	ft_printf("→ Returns: ft_printf=%d printf=%d ", ret_ft, ret_og);
	ft_printf("%s\n", (ret_ft == ret_og) ? "\033[0;32m✓\033[0m" : "\033[0;31m✗\033[0m");
}

void	test_edge_char(void)
{
	int	ret_ft;
	int	ret_og;

	test_section("printf(\"%c%c%c\", 'A', 'B', 'C')");
	ft_printf("\033[0;90mExpected: ABC\033[0m\n");
	ret_ft = ft_printf("\033[0;36mft_printf:\033[0m %c%c%c\n", 'A', 'B', 'C');
	ret_og = printf("\033[0;33m   printf:\033[0m %c%c%c\n", 'A', 'B', 'C');
	ft_printf("→ %s\n", (ret_ft == ret_og) ? "\033[0;32m✓\033[0m" : "\033[0;31m✗\033[0m");
	test_section("printf(\"%c\", 0)");
	ft_printf("\033[0;90mExpected: (null char, invisible)\033[0m\n");
	ret_ft = ft_printf("\033[0;36mft_printf:\033[0m %c\n", 0);
	ret_og = printf("\033[0;33m   printf:\033[0m %c\n", 0);
	ft_printf("→ %s\n", (ret_ft == ret_og) ? "\033[0;32m✓\033[0m" : "\033[0;31m✗\033[0m");
}

void	test_edge_string(void)
{
	int		ret_ft;
	int		ret_og;
	char	*null;

	null = NULL;
	test_section("printf(\"%s\", NULL)");
	ft_printf("\033[0;90mExpected: (null)\033[0m\n");
	ret_ft = ft_printf("\033[0;36mft_printf:\033[0m %s\n", null);
	ret_og = printf("\033[0;33m   printf:\033[0m %s\n", null);
	ft_printf("→ %s\n", (ret_ft == ret_og) ? "\033[0;32m✓\033[0m" : "\033[0;31m✗\033[0m");
	test_section("printf(\"[%s]\", \"\")");
	ft_printf("\033[0;90mExpected: []\033[0m\n");
	ret_ft = ft_printf("\033[0;36mft_printf:\033[0m [%s]\n", "");
	ret_og = printf("\033[0;33m   printf:\033[0m [%s]\n", "");
	ft_printf("→ %s\n", (ret_ft == ret_og) ? "\033[0;32m✓\033[0m" : "\033[0;31m✗\033[0m");
}

void	test_edge_ptr(void)
{
	int		ret_ft;
	int		ret_og;
	void	*null;

	null = NULL;
	test_section("printf(\"%p\", NULL)");
	ft_printf("\033[0;90mExpected: (nil)\033[0m\n");
	ret_ft = ft_printf("\033[0;36mft_printf:\033[0m %p\n", null);
	ret_og = printf("\033[0;33m   printf:\033[0m %p\n", null);
	ft_printf("→ %s\n", (ret_ft == ret_og) ? "\033[0;32m✓\033[0m" : "\033[0;31m✗\033[0m");
	test_section("printf(\"%p\", &var)");
	ft_printf("\033[0;90mExpected: 0x...\033[0m\n");
	ret_ft = ft_printf("\033[0;36mft_printf:\033[0m %p\n", &null);
	ret_og = printf("\033[0;33m   printf:\033[0m %p\n", &null);
	ft_printf("→ %s\n", (ret_ft == ret_og) ? "\033[0;32m✓\033[0m" : "\033[0;31m✗\033[0m");
}

void	test_edge_int(void)
{
	int	ret_ft;
	int	ret_og;

	test_section("printf(\"%d | %d\", INT_MIN, INT_MAX)");
	ft_printf("\033[0;90mExpected: -2147483648 | 2147483647\033[0m\n");
	ret_ft = ft_printf("\033[0;36mft_printf:\033[0m %d | %d\n", (int)-2147483648, 2147483647);
	ret_og = printf("\033[0;33m   printf:\033[0m %d | %d\n", (int)-2147483648, 2147483647);
	ft_printf("→ %s\n", (ret_ft == ret_og) ? "\033[0;32m✓\033[0m" : "\033[0;31m✗\033[0m");
	test_section("printf(\"%d %d %d\", -42, 0, 42)");
	ft_printf("\033[0;90mExpected: -42 0 42\033[0m\n");
	ret_ft = ft_printf("\033[0;36mft_printf:\033[0m %d %d %d\n", -42, 0, 42);
	ret_og = printf("\033[0;33m   printf:\033[0m %d %d %d\n", -42, 0, 42);
	ft_printf("→ %s\n", (ret_ft == ret_og) ? "\033[0;32m✓\033[0m" : "\033[0;31m✗\033[0m");
}

void	test_edge_unsigned(void)
{
	int	ret_ft;
	int	ret_og;

	test_section("printf(\"%u\", 4294967295)");
	ft_printf("\033[0;90mExpected: 4294967295\033[0m\n");
	ret_ft = ft_printf("\033[0;36mft_printf:\033[0m %u\n", 4294967295u);
	ret_og = printf("\033[0;33m   printf:\033[0m %u\n", 4294967295u);
	ft_printf("→ %s\n", (ret_ft == ret_og) ? "\033[0;32m✓\033[0m" : "\033[0;31m✗\033[0m");
	test_section("printf(\"%u\", -1)");
	ft_printf("\033[0;90mExpected: 4294967295 (wraps)\033[0m\n");
	ret_ft = ft_printf("\033[0;36mft_printf:\033[0m %u\n", -1);
	ret_og = printf("\033[0;33m   printf:\033[0m %u\n", -1);
	ft_printf("→ %s\n", (ret_ft == ret_og) ? "\033[0;32m✓\033[0m" : "\033[0;31m✗\033[0m");
}

void	test_edge_hex(void)
{
	int	ret_ft;
	int	ret_og;

	test_section("printf(\"%x\", 255)");
	ft_printf("\033[0;90mExpected: ff\033[0m\n");
	ret_ft = ft_printf("\033[0;36mft_printf:\033[0m %x\n", 255);
	ret_og = printf("\033[0;33m   printf:\033[0m %x\n", 255);
	ft_printf("→ %s\n", (ret_ft == ret_og) ? "\033[0;32m✓\033[0m" : "\033[0;31m✗\033[0m");
	test_section("printf(\"%X\", 255)");
	ft_printf("\033[0;90mExpected: FF\033[0m\n");
	ret_ft = ft_printf("\033[0;36mft_printf:\033[0m %X\n", 255);
	ret_og = printf("\033[0;33m   printf:\033[0m %X\n", 255);
	ft_printf("→ %s\n", (ret_ft == ret_og) ? "\033[0;32m✓\033[0m" : "\033[0;31m✗\033[0m");
	test_section("printf(\"%x\", -1)");
	ft_printf("\033[0;90mExpected: ffffffff\033[0m\n");
	ret_ft = ft_printf("\033[0;36mft_printf:\033[0m %x\n", -1);
	ret_og = printf("\033[0;33m   printf:\033[0m %x\n", -1);
	ft_printf("→ %s\n", (ret_ft == ret_og) ? "\033[0;32m✓\033[0m" : "\033[0;31m✗\033[0m");
}

void	test_edge_percent(void)
{
	int	ret_ft;
	int	ret_og;

	test_section("printf(\"100%% complete\")");
	ft_printf("\033[0;90mExpected: 100%% complete\033[0m\n");
	ret_ft = ft_printf("\033[0;36mft_printf:\033[0m 100%% complete\n");
	ret_og = printf("\033[0;33m   printf:\033[0m 100%% complete\n");
	ft_printf("→ %s\n", (ret_ft == ret_og) ? "\033[0;32m✓\033[0m" : "\033[0;31m✗\033[0m");
}

void	test_mix_batard(void)
{
	int	ret_ft;
	int	ret_og;

	test_section("printf(\"%c%s%p%d%i%u%x%X%%\", ...)");
	ft_printf("\033[0;90mAll 9 conversions: 'A' \"B\" NULL -42 42 0 255 255\033[0m\n");
	ret_ft = ft_printf("\033[0;36mft_printf:\033[0m %c%s%p%d%i%u%x%X%%\n", 'A', "B",
			NULL, -42, 42, 0, 255, 255);
	ret_og = printf("\033[0;33m   printf:\033[0m %c%s%p%d%i%u%x%X%%\n", 'A', "B",
			NULL, -42, 42, 0, 255, 255);
	ft_printf("→ %s\n", (ret_ft == ret_og) ? "\033[0;32m✓\033[0m" : "\033[0;31m✗\033[0m");
}

void	test_return_value(void)
{
	int	ret_ft;
	int	ret_og;

	test_section("Return value test");
	ft_printf("\033[0;90mMust return number of chars printed\033[0m\n");
	ret_ft = ft_printf("0123456789");
	ret_og = printf("0123456789");
	ft_printf("\n→ ft_printf=%d printf=%d %s\n", ret_ft, ret_og,
		(ret_ft == ret_og) ? "\033[0;32m✓\033[0m" : "\033[0;31m✗\033[0m");
}

int	main(void)
{
	ft_printf("\n\033[1;36m╔══════════════════════════════════╗\033[0m\n");
	ft_printf("\033[1;36m║   \033[1;33mFT_PRINTF TESTER\033[1;36m           ║\033[0m\n");
	ft_printf("\033[1;36m╚══════════════════════════════════╝\033[0m\n");
	test_basic();
	test_edge_char();
	test_edge_string();
	test_edge_ptr();
	test_edge_int();
	test_edge_unsigned();
	test_edge_hex();
	test_edge_percent();
	test_mix_batard();
	test_return_value();
	ft_printf("\n\033[1;32m✓✓✓ ALL TESTS PASSED ✓✓✓\033[0m\n\n");
	return (0);
}
