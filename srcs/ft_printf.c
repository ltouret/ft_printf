/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 18:03:55 by ltouret           #+#    #+#             */
/*   Updated: 2020/05/19 16:31:48 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include "../test.c"

// TODO ERASE INCLUDES AND PRINTFS

void	test_print(char *fmt, t_list *lst)
{
	int		i;
	int		out;

	i = 0;
	out = 0;
	printf("%s", fmt);
	while (i < ft_strlen(fmt))
	{
		while (fmt[i] == '%' && fmt[i++])
		{
			if (lst)
			{
				printf("%s", ((t_block*)lst->content)->converted);
				out += ft_strlen(((t_block*)lst->content)->converted);
				lst = lst->next;
			}
			i = find_term_char(fmt + i) + i + 1;
		}
		printf("%c", fmt[i]);
		i++;
	}
	printf("len: %d\n", out);
}

int		ft_printf(char *str, ...)
{
	va_list	args;
	t_list	*lst;

	lst = NULL;
	va_start(args, str);
	if (parsing_str(str, &lst) == -1)
		return (-1);
	if (get_param(lst, args) == -1)
		return (-1);
	if (convert_fir(lst) == -1)
		return (-1);
	if (apply_mod(lst) == -1)
		return (-1);
	test_print(str, lst);
	va_end(args);
	return (-1);
}

int main()
{
	printf("pr len: %d\n", printf("%c", '\0'));
	ft_printf("%c", '\0');
	printf("pr len: %d\n", printf("%c", 'a'));
	ft_printf("%c", 'a');
	/*
	char *test = "hello %*.*d %.3d %-5d %u %p %c%s %%\n";
	ft_printf(test, 5, 4, -10, 1, 4, 3, "n", 'a', "sapo");
	printf("hislen: %d\n", printf(test,  5, 4, -10, 1, 4, 3, "n", 'a', "sapo"));
	printf("hislen: %d\n", printf("li%-5cli\n", 'a'));
	printf("hislen: %d\n", printf("%c", '\0'));
	ft_printf("%c", '\0');
	ft_printf("li%-5cli\n", 'a');
	*/
	//ft_printf("%05d\n", -3);
	//ft_printf("mine:%5c\n", '\0');
	//printf("hiss:%5c\n", '\0');
	/*printf("%.0s\n", "heelo");
	printf("%.0d\n", 0);
	printf ("%-.10s\n", "hey");
	printf("%c\n", '\0');
	int a = printf("%d %% a\n", 30);
	printf("%d\n", a);
	printf("%d\n", printf("%c\n", '-'));*/
	//printf("\ntest : %*.*d\n", 10, 6, 12359);
	/*printf("");
	printf("%%");
	printf("%5.%");*/

	/* -- tests for parsing var string -- */
	
	//char *test = "%*.d %u %p %c %%\n";
	//wtf is this sh*t - rpi
	//printf("%d\n");
	//printf("%d\n");

	/*char *str1 = ultoa_base((unsigned long) test, "0123456789abcdef");
	char *str2 = ft_strjoin("0x", str1);
	printf("lol: %s\n", str2);*/
	
	//printf("%d %d", find(test , '%'), find_term_char(test + 1));
	//ft_printf("p", "hello my friend", 4, 5);
}
