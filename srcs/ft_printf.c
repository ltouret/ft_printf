/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 18:03:55 by ltouret           #+#    #+#             */
/*   Updated: 2020/05/23 20:28:22 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			free_block(void *content)
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

static t_block		*skp_char(t_list *lst, char *str, int *i,
		int *total_char)
{
	while (str[*i] && str[*i] != '%')
	{
		ft_putchar_fd(str[(*i)++], 1);
		(*total_char)++;
	}
	if (lst)
		return (lst->content);
	else
		return (NULL);
}

static void			print_conv(t_block *block, int *total_char)
{
	int		i;

	i = 0;
	if (block->type == 'c')
	{
		while (block->raw_block[i] && block->raw_block[i] != '-')
			i++;
		if (block->raw_block[i] == '-')
		{
			if ((*(int *)block->param) == '\0' && (*total_char)++)
				ft_putchar_fd('\0', 1);
			ft_putstr_fd(block->converted, 1);
		}
		else
		{
			ft_putstr_fd(block->converted, 1);
			if ((*(int *)block->param) == '\0' && (*total_char)++)
				ft_putchar_fd('\0', 1);
		}
	}
	else
		ft_putstr_fd(block->converted, 1);
	*total_char += ft_strlen(block->converted);
}

static int			print_char(char *str, t_list *lst)
{
	t_block		*block;
	int			total_char;
	int			i;

	total_char = 0;
	i = 0;
	while (str && str[i])
	{
		block = skp_char(lst, str, &i, &total_char);
		if (str[i] == '%')
		{
			print_conv(block, &total_char);
			if (str[++i] == '%')
				;
			else
				while (str[i] && ft_find("cspdiuxX%", str[i]) == -1)
					i++;
			i++;
			lst = lst->next;
		}
	}
	return (total_char);
}

int					ft_printf(const char *str, ...)
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
	ft_lstclear(&lst, &free_block);
	return (total_char);
}
