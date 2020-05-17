/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 18:03:55 by ltouret           #+#    #+#             */
/*   Updated: 2020/05/16 20:05:49 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../test.c"

// TODO ERASE INCLUDES AND PRINTFS

void	test_print(char *fmt, t_list *lst)
{
	int i;

	i = 0;
	printf("%s", fmt);
	while (fmt && i < ft_strlen(fmt))
	{
		while (fmt[i] == '%' && fmt[i++])
		{
			if (lst)
			{
				printf("%s", ((t_block*)lst->content)->converted);
				lst = lst->next;
			}
			i = find_term_char(fmt + i) + i + 1;
		}
		printf("%c", fmt[i]);
		i++;
	}
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
