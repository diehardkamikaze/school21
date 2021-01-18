/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:47:51 by mchau             #+#    #+#             */
/*   Updated: 2021/01/18 10:41:23 by mchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>
#include <assert.h>
#include "ft_printf.h"

int g_special_random_fd = 0;

int	PRINT_F(char *format, ...)
{
	int system_res;
	int user_res;

	va_list ptr;
	va_list ptr_copy;
	va_copy(ptr_copy, ptr);
	va_start(ptr, format);
	va_start(ptr_copy, format);

	system_res = vdprintf(g_special_random_fd, format, ptr);
	vdprintf(g_special_random_fd, "\n", ptr);
	user_res = ft_vprintf(format, ptr_copy);
	va_end(ptr);
	va_end(ptr_copy);
	vdprintf(1, "\n", ptr);
	return (system_res == user_res);
}
void	start_tests()
{
	assert(PRINT_F("test: %.%"));
	assert(PRINT_F("test: %.10%"));
	assert(PRINT_F("test: %.*%", -10));
	assert(PRINT_F("test: %10.%"));
	assert(PRINT_F("test: %*.%", -10));
	assert(PRINT_F("test: %9.10%"));
	assert(PRINT_F("test: %*.10%,", -1));
	assert(PRINT_F("test: %9.*%", -10));
	assert(PRINT_F("test: %*.*%", -8, -7));

	assert(PRINT_F("test: %-.%"));
	assert(PRINT_F("test: %-.10%"));
	assert(PRINT_F("test: %-.*%", -10));
	assert(PRINT_F("test: %-10.%"));
	assert(PRINT_F("test: %-*.%", -10));
	assert(PRINT_F("test: %-9.10%"));
	assert(PRINT_F("test: %-*.10%", -19));
	assert(PRINT_F("test: %-9.*%", -10));
	assert(PRINT_F("test: %-*.*%", -8, -7));

	assert(PRINT_F("test: %0.%"));
	assert(PRINT_F("test: %0.10%"));
	assert(PRINT_F("test: %0.*%", -10));
	assert(PRINT_F("test: %010.%"));
	assert(PRINT_F("test: %0*.%", -10));
	assert(PRINT_F("test: %09.10%"));
	assert(PRINT_F("test: %0*.10%", -19));
	assert(PRINT_F("test: %09.*%", -10));
	assert(PRINT_F("test: %0*.*%", -8, -7));

	assert(PRINT_F("test: %-0.%"));
	assert(PRINT_F("test: %-0.10%"));
	assert(PRINT_F("test: %-0.*%", -10));
	assert(PRINT_F("test: %-010.%"));
	assert(PRINT_F("test: %-0*.%", -10));
	assert(PRINT_F("test: %-09.10%"));
	assert(PRINT_F("test: %-0*.10%", -19));
	assert(PRINT_F("test: %-09.*%", -10));
	assert(PRINT_F("test: %-0*.*%", -8, -7));

	/* end of %% tests  */

	/* %c tests */
	assert(PRINT_F("test: %c", 88));
	assert(PRINT_F("test: %10c", 89));
	assert(PRINT_F("test: %*c", -89));

	assert(PRINT_F("test: -%c", 88));
	assert(PRINT_F("test: %-10c", 89));
	assert(PRINT_F("test: %-*c", -89));

	/* end of %c tests */

	/* %s tests */
	assert(PRINT_F("test: %s", "almaz"));
	assert(PRINT_F("test: %.s", "almazyan"));
	assert(PRINT_F("test: %.*s", 0, "toptoptoptop"));
	assert(PRINT_F("test: %.*s", -8, "almaz"));
	assert(PRINT_F("test: %.10s", "almaz"));
	assert(PRINT_F("test: %.4s", "almaz"));
	assert(PRINT_F("test: %2s", "almaz"));
	assert(PRINT_F("test: %12s", "almaz"));
	assert(PRINT_F("test: %2.s", "almaz"));
	assert(PRINT_F("test: %*.s", 2, "almaz"));
	assert(PRINT_F("test: %*.s", 16, "almaz"));
	assert(PRINT_F("test: %*.*s", -8, -8, "almaz"));
	assert(PRINT_F("test: %*.*s", 17, -8, "almaz"));
	assert(PRINT_F("test: %*.*s", 2, -8, "almaz"));
	assert(PRINT_F("test: %*.10s", -10,  "almaz"));
	assert(PRINT_F("test: %*.10s", 3, "almaz"));
	assert(PRINT_F("test: %*.10s", 8, "almaz"));
	assert(PRINT_F("test: %12.*s", 3, "almaz"));
	assert(PRINT_F("test: %99.*s", 3,"almaz"));

	assert(PRINT_F("test: %-s", "almaz"));
	assert(PRINT_F("test: %-.s", "almazyan"));
	assert(PRINT_F("test: %-.*s", 0, "toptoptoptop"));
	assert(PRINT_F("test: %-.*s", -8, "almaz"));
	assert(PRINT_F("test: %-.10s", "almaz"));
	assert(PRINT_F("test: %-.4s", "almaz"));
	assert(PRINT_F("test: %-2s", "almaz"));
	assert(PRINT_F("test: %-12s", "almaz"));
	assert(PRINT_F("test: %-2.s", "almaz"));
	assert(PRINT_F("test: %-*.s", 2, "almaz"));
	assert(PRINT_F("test: %-*.s", 16, "almaz"));
	assert(PRINT_F("test: %-*.*s", -8, -8, "almaz"));
	assert(PRINT_F("test: %-*.*s", 17, -8, "almaz"));
	assert(PRINT_F("test: %-*.*s", 2, -8, "almaz"));
	assert(PRINT_F("test: %--*.10s", -10,  "almaz"));
	assert(PRINT_F("test: %-*.10s", 3, "almaz"));
	assert(PRINT_F("test: %-*.10s", 8, "almaz"));
	assert(PRINT_F("test: %-12.*s", 3, "almaz"));
	assert(PRINT_F("test: %-99.*s", 3,"almaz"));

	assert(PRINT_F("test: %s", (void *)0));
	assert(PRINT_F("test: %.s", (void *)0));
	assert(PRINT_F("test: %.*s", 0, (void *)0));
	assert(PRINT_F("test: %.*s", -8, (void *)0));
	assert(PRINT_F("test: %.10s", (void *)0));
	assert(PRINT_F("test: %.4s", (void *)0));
	assert(PRINT_F("test: %2s", (void *)0));
	assert(PRINT_F("test: %12s", (void *)0));
	assert(PRINT_F("test: %2.s", (void *)0));
	assert(PRINT_F("test: %*.s", 2, (void *)0));
	assert(PRINT_F("test: %*.s", 16, (void *)0));
	assert(PRINT_F("test: %*.*s", -8, -8, (void *)0));
	assert(PRINT_F("test: %*.*s", 17, -8, (void *)0));
	assert(PRINT_F("test: %*.*s", 2, -8, (void *)0));
	assert(PRINT_F("test: %*.10s", -10, (void *)0));
	assert(PRINT_F("test: %*.10s", 3, (void *)0));
	assert(PRINT_F("test: %*.10s", 8, (void *)0));
	assert(PRINT_F("test: %12.*s", 3, (void *)0));
	assert(PRINT_F("test: %99.*s", 3,(void *)0));

	assert(PRINT_F("test: %-s", (void *)0));
	assert(PRINT_F("test: %-.s", "almazyan"));
	assert(PRINT_F("test: %-.*s", 0, "toptoptoptop"));
	assert(PRINT_F("test: %-.*s", -8, (void *)0));
	assert(PRINT_F("test: %-.10s", (void *)0));
	assert(PRINT_F("test: %-.4s", (void *)0));
	assert(PRINT_F("test: %-2s", (void *)0));
	assert(PRINT_F("test: %-12s", (void *)0));
	assert(PRINT_F("test: %-2.s", (void *)0));
	assert(PRINT_F("test: %-*.s", 2, (void *)0));
	assert(PRINT_F("test: %-*.s", 16, (void *)0));
	assert(PRINT_F("test: %-*.*s", -8, -8, (void *)0));
	assert(PRINT_F("test: %-*.*s", 17, -8, (void *)0));
	assert(PRINT_F("test: %-*.*s", 2, -8, (void *)0));
	assert(PRINT_F("test: %--*.10s", -10,  (void *)0));
	assert(PRINT_F("test: %-*.10s", 3, (void *)0));
	assert(PRINT_F("test: %-*.10s", 8, (void *)0));
	assert(PRINT_F("test: %-12.*s", 3, (void *)0));
	assert(PRINT_F("test: %-99.*s", 3,(void *)0));
	/* end of %s tests */

	/* d_i_handler */


     assert(PRINT_F("test: %d", 88));
     assert(PRINT_F("test: %.1d", 90));
     assert(PRINT_F("test: %.20d", 21));
     assert(PRINT_F("test: %.d", 188));;
     assert(PRINT_F("test: %.d", -329));
     assert(PRINT_F("test: %.1d", -90));
     assert(PRINT_F("test: %.20d", -21));
     assert(PRINT_F("test: %.*d", -29, -188));
     assert(PRINT_F("test: %.*d", -30,  90));

    assert(PRINT_F("test: %10d", 90));
     assert(PRINT_F("test: %10d", -21));
     assert(PRINT_F("test: %5d",-567566));
     assert(PRINT_F("test: %4d", 866454));
     assert(PRINT_F("test: %*d", -29, -188));
     assert(PRINT_F("test: %*d", -30,  90));

     assert(PRINT_F("test: %10.1d", 90));
     assert(PRINT_F("test: %10.5d", 90));
     assert(PRINT_F("test: %10.20d", 90));
     assert(PRINT_F("test: %10.1d", -90));
     assert(PRINT_F("test: %10.5d", -90));
     assert(PRINT_F("test: %10.20d", -90));
     assert(PRINT_F("test: %10.d", 155));;
     assert(PRINT_F("test: %9.d", 644));
     assert(PRINT_F("test: %4.d", 87656));
     assert(PRINT_F("test: %10.d", -155));
     assert(PRINT_F("test: %9.d", -644));
     assert(PRINT_F("test: %4.d", -87656));
     assert(PRINT_F("test: %*.*d", 5, 3, 155466456));
     assert(PRINT_F("test: %*.*d", 5, 3, 155466456));
     assert(PRINT_F("test: %*.*d", 5, 3, 155466456));
     assert(PRINT_F("test: %*.*d", 5, 3, -54535454));

     assert(PRINT_F("test: %*.*d", 3, 5, 155466456));
     assert(PRINT_F("test: %*.*d", 3, 5, 155466456));
     assert(PRINT_F("test: %*.*d", 3, 5, 155466456));
     assert(PRINT_F("test: %*.*d", 3, 5, -54535454));
     assert(PRINT_F("test: %*.*d", -5, -3, -54535454));
     assert(PRINT_F("test: %*.*d", -5, 3, -54535454));
     assert(PRINT_F("test: %*.*d", 5, -3, -54535454));
     assert(PRINT_F("test: %*.*d", -3, -5, 155466456));
     assert(PRINT_F("test: %*.*d", 3, -5, 155466456));
     assert(PRINT_F("test: %*.*d", -3, 5, 155466456));

	 assert(PRINT_F("test: %-d", 88));
     assert(PRINT_F("test: %-.1d", 90));
     assert(PRINT_F("test: %-.20d", 21));
     assert(PRINT_F("test: %-.d", 188));;
     assert(PRINT_F("test: %-.d", -329));
     assert(PRINT_F("test: %-.1d", -90));
     assert(PRINT_F("test: %-.20d", -21));
     assert(PRINT_F("test: %-.*d", -29, -188));
     assert(PRINT_F("test: %-.*d", -30,  90));

    assert(PRINT_F("test: %-10d", 90));
     assert(PRINT_F("test: %-10d", -21));
     assert(PRINT_F("test: %-5d",-567566));
     assert(PRINT_F("test: %-4d", 866454));
     assert(PRINT_F("test: %-*d", -29, -188));
     assert(PRINT_F("test: %-*d", -30,  90));

     assert(PRINT_F("test: %-10.1dl", 90));
     assert(PRINT_F("test: %-10.5d", 90));
     assert(PRINT_F("test: %-10.20d", 90));
     assert(PRINT_F("test: %-10.1d", -90));
     assert(PRINT_F("test: %-10.5d", -90));
     assert(PRINT_F("test: %-10.20d", -90));
     assert(PRINT_F("test: %-10.d", 155));;
     assert(PRINT_F("test: %-9.d", 644));
     assert(PRINT_F("test: %-4.d", 87656));
     assert(PRINT_F("test: %-10.d", -155));
     assert(PRINT_F("test: %-9.d", -644));
     assert(PRINT_F("test: %-4.d", -87656));
     assert(PRINT_F("test: %-*.*d", 5, 3, 155466456));
     assert(PRINT_F("test: %-*.*d", 5, 3, 155466456));
     assert(PRINT_F("test: %-*.*d", 5, 3, 155466456));
     assert(PRINT_F("test: %-*.*d", 5, 3, -54535454));

     assert(PRINT_F("test: %-*.*d", 3, 5, 155466456));
     assert(PRINT_F("test: %-*.*d", 3, 5, 155466456));
     assert(PRINT_F("test: %-*.*d", 3, 5, 155466456));
     assert(PRINT_F("test: %-*.*d", 3, 5, -54535454));
     assert(PRINT_F("test: %-*.*d", -5, -3, -54535454));
     assert(PRINT_F("test: %-*.*d", -5, 3, -54535454));
     assert(PRINT_F("test: %-*.*d", 5, -3, -54535454));
     assert(PRINT_F("test: %-*.*d", -3, -5, 155466456));
     assert(PRINT_F("test: %-*.*d", 3, -5, 155466456));
     assert(PRINT_F("test: %-*.*d", -3, 5, 155466456));

	 assert(PRINT_F("test: %0d", 88));
     assert(PRINT_F("test: %0.1d", 90));
     assert(PRINT_F("test: %0.20d", 21));
     assert(PRINT_F("test: %0.d", 188));;
     assert(PRINT_F("test: %0.d", -329));
     assert(PRINT_F("test: %0.1d", -90));
     assert(PRINT_F("test: %0.20d", -21));
     assert(PRINT_F("test: %0.*d", -29, -188));
     assert(PRINT_F("test: %0.*d", -30,  90));

    assert(PRINT_F("test: %010d", 90));
     assert(PRINT_F("test: %010d", -21));
     assert(PRINT_F("test: %05d",-567566));
     assert(PRINT_F("test: %04d", 866454));
     assert(PRINT_F("test: %0*d", -29, -188));
     assert(PRINT_F("test: %0*d", -30,  90));

     assert(PRINT_F("test: %010.1d", 90));
     assert(PRINT_F("test: %010.5d", 90));
     assert(PRINT_F("test: %010.20d", 90));
     assert(PRINT_F("test: %010.1d", -90));
     assert(PRINT_F("test: %010.5d", -90));
     assert(PRINT_F("test: %010.20d", -90));
     assert(PRINT_F("test: %010.d", 155));;
     assert(PRINT_F("test: %09.d", 644));
     assert(PRINT_F("test: %04.d", 87656));
     assert(PRINT_F("test: %010.d", -155));
     assert(PRINT_F("test: %09.d", -644));
     assert(PRINT_F("test: %04.d", -87656));
     assert(PRINT_F("test: %0*.*d", -5, 3, 155466456));
     assert(PRINT_F("test: %0*.*d", -5, 3, 155466456));
     assert(PRINT_F("test: %0*.*d", -5, 3, 155466456));
     assert(PRINT_F("test: %0*.*d", -5, 3, -54535454));

     assert(PRINT_F("test: %*.*d", 3, 5, 155466456));
     assert(PRINT_F("test: %*.*d", 3, 5, 155466456));
     assert(PRINT_F("test: %*.*d", 3, 5, 155466456));
     assert(PRINT_F("test: %*.*d", 3, 5, -54535454));
     assert(PRINT_F("test: %*.*d", -5, -3, -54535454));
     assert(PRINT_F("test: %*.*d", -5, 3, -54535454));
     assert(PRINT_F("test: %*.*d", 5, -3, -54535454));
     assert(PRINT_F("test: %*.*d", -3, -5, 155466456));
     assert(PRINT_F("test: %*.*d", 3, -5, 155466456));
     assert(PRINT_F("test: %*.*d", -3, 5, 155466456));
}

int		main(void)
{
	g_special_random_fd = open("system_printf_output", O_WRONLY | O_TRUNC);
	if (g_special_random_fd != -1)
		start_tests();
	return (0);
}
