#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "ft_printf.h"

int ft_printf(const char *fmt, ...)
{
	va_list args;
	char c;

	va_start(args, fmt);

	while ((c = *fmt) != '\0')
	{
		//printf("%c\n", c);
		if (c == 'd')
		{
			char *tmp = ft_itoa(va_arg(args, int));
			ft_putendl_fd(tmp, 1);
			//printf("%s\n", tmp);
		}
		fmt++;
	}
	printf("%s", fmt);
	va_end(args);
	return (-1);
}
