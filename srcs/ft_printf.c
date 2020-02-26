#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "ft_printf.h"
#include "../libft/libft.h"

int ft_printf(const char *fmt, ...)
{
	va_list args;
	char c;
	char *tmp;

	va_start(args, fmt);

	while ((c = *fmt) != '\0')
	{
		//printf("%c\n", c);
		if (c == 'd')
		{
			tmp = ft_itoa(va_arg(args, int));
			ft_putstr_fd(tmp, 1);
			//printf("%s\n", tmp);
		}
		else if (c == 's')
		{
			tmp = va_arg(args, char *);
			ft_putstr_fd(tmp, 1);
		}
		else if (c == 'c')
		{
			ft_putchar_fd(va_arg(args, int), 1);
		}
		else if (c == 'p')
		{
			unsigned long pt = (unsigned long)va_arg(args, void*);
			tmp = ft_itoa(pt);
//			ft_putstr_fd(ft_itoa(-1), 1);
			ft_putendl_fd(tmp, 1);
		}
		fmt++;
	}
	printf("%s", fmt);
	va_end(args);
	return (-1);
}
