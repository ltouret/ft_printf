/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 18:03:55 by ltouret           #+#    #+#             */
/*   Updated: 2020/05/20 18:21:52 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clear_block(void *content)
{
	t_block		*block;

	block = content;
	if (block->raw_block)
		free(block->raw_block);
	if (block->param && block->type != 's' && block->type != 'p')
		free(block->param);
	if (block->wildcard[0])
		free(block->wildcard[0]);
	if (block->wildcard[1])
		free(block->wildcard[1]);
	if (block->converted)
		free(block->converted);
	free(block);
}

int		print_char(char *str, t_list *lst)
{
	int		i;
	int		out;

	i = -1;
	out = 0;
	while (++i < ft_strlen(str))
	{
		while (str[i] == '%' && str[i++])
		{
			if (lst)
			{
				ft_putstr_fd(((t_block*)lst->content)->converted, 1);
				out += ft_strlen(((t_block*)lst->content)->converted);
				if (*((t_block*)lst->content)->converted == '\0' &&
					((t_block*)lst->content)->type == 'c')
					out++;
				lst = lst->next;
			}
			i = find_term_char(str + i) + i + 1;
		}
		ft_putchar_fd(str[i], 1);
		if (str[i] != '\0')
			out++;
	}
	return (out);
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	t_list	*lst;
	int		total_char;

	lst = NULL;
	va_start(args, str);
	if (parsing_str((char *)str, &lst) == -1)
		return (-1);
	if (get_param(lst, args) == -1)
		return (-1);
	if (convert_fir(lst) == -1)
		return (-1);
	if (apply_mod(lst) == -1)
		return (-1);
	va_end(args);
	total_char = print_char((char *)str, lst);
	ft_lstclear(&lst, &clear_block);
	return (total_char);
}
